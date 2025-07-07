#include "Game.h"
#include "CharacterManager.h"
#include "ItemManager.h"
#include "SkillManager.h"
#include "ProfileManager.h"
#include "Utils.h"
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>
using namespace std;
// Lista completa de personajes predeterminados para seleccionar enemigo
static const vector<Character> ALL_DEFAULT_CHARACTERS = {
    {"Footman",1,16,0}, {"Pyromancer",1,0,0},   {"Hydromancer",1,1,0},
    {"Earthshaper",1,2,0},{"Aeromancer",1,3,0}, {"Electroknight",1,4,0},
    {"Cryomancer",1,5,0},{"Iron Golem",1,6,0},  {"Beastmaster",1,7,0},
    {"Mystic Sage",1,8,0},{"Necromancer",1,9,0},{"Cleric",1,10,0},
    {"Shadowblade",1,11,0},{"Druid",1,12,0},    {"Venomancer",1,13,0},
    {"Psychic Monk",1,14,0},{"Dragon Knight",1,15,0},{"Rockguard",1,17,0}
};

// Estructura para llevar el objeto equipado y su índice en inventario
struct Equipped {
    float dmgPct = 0.0f;
    float dodgePct = 0.0f;
    int duration = 0;
    int invIndex = -1;
    string name;
};

void startGame(const string &username) {
    srand((unsigned)time(nullptr));
    cout << "\n=== Start Battle ===\n";

    // Preparar datos del usuario
    int lvl       = getUserLevel(username);
    auto defsLvl  = getDefaultCharactersUpToLevel(lvl);
    loadCharacters(username);
    auto customs  = getCharacters();
    loadSkills();
    loadInventory(username);

    // Equipar un objeto antes de la batalla 
    Equipped eq;
    cout << "\nEquip an item before battle? (0 to skip)\n";
    auto inv = getInventory();  // copia local
    for (size_t i = 0; i < inv.size(); ++i) {
        cout << i+1 << ") " << inv[i].name
                  << " (" << inv[i].duration << " turns remaining)\n";
    }
    cout << "Choose item #: ";
    int it = getIntInput(0, (int)inv.size());
    if (it > 0) {
        int idx = it - 1;
        eq.name     = inv[idx].name;
        eq.duration = inv[idx].duration;
        eq.invIndex = idx;
        // Asignar efectos según nombre
        if (eq.name == "Rusted Longsword")        eq.dmgPct = 0.10f;
        else if (eq.name == "Ashen Warblade")     eq.dmgPct = 0.20f;
        else if (eq.name == "Bone Cleaver")       eq.dmgPct = 0.30f;
        else if (eq.name == "Serpent’s Rapier")   eq.dodgePct = 0.10f;
        else if (eq.name == "Sunforged Greatsword") eq.dmgPct = 0.25f;
        else if (eq.name == "Frostbrand Axe")     eq.dodgePct = 0.15f;
        else if (eq.name == "Thunderstrike Mace") eq.dmgPct = 0.40f;
        else if (eq.name == "Mercurial Dagger")   eq.dmgPct = 0.05f, eq.dodgePct = 0.05f;
        else if (eq.name == "Draconic Halberd")   eq.dmgPct = 0.50f;
        else if (eq.name == "Wraithblade")        eq.dodgePct = 0.20f;
        cout << "Equipped " << eq.name
                  << " (" << eq.duration << " turns)\n";
    }

    // --- Selección de personaje del jugador ---
    cout << "\n1) Default ("<<defsLvl.size()<<")  2) Yours("<<customs.size()<<") 3) Back\nChoose: ";
    int pc = getIntInput(1,3);
    if (pc == 3) return;
    auto pool = (pc == 2 && !customs.empty()) ? customs : defsLvl;

    cout << "\nSelect your character:\n";
    for (size_t i = 0; i < pool.size(); ++i) {
        cout << "  " << i+1 << ") " << pool[i].name
                  << " (" << getTypeName(pool[i].typeID) << ")\n";
    }
    int pidx = getIntInput(1, pool.size()) - 1;
    Character player = pool[pidx];
    cout << "\nYou: " << player.name << "\n";

    // Selección aleatoria del enemigo entre todos los defaults 
    Character enemy = ALL_DEFAULT_CHARACTERS[rand() % ALL_DEFAULT_CHARACTERS.size()];
    cout << "Enemy: " << enemy.name
              << " (" << getTypeName(enemy.typeID) << ")\n";

    // Estadísticas de combate 
    int pHp = 30, eHp = 30, pAP = 0, eAP = 0;
    auto &skills = getAllSkills();
    const int dodgeBase = 20;

    // Bucle de combate 
    while (pHp > 0 && eHp > 0) {
        // Mostrar HP al inicio de cada turno
        cout << "\n[Status] You: " << pHp 
                  << " HP | Enemy: " << eHp << " HP\n";

        // Tirada de dados
        cout << "-- Roll dice (ENTER) --"; cin.get();
        int pr = rand() % 6 + 1;
        int er = rand() % 6 + 1;
        cout << "\nYou rolled:  " << pr 
                  << "    Enemy rolled: " << er << "\n";

        if (pr > er) {
            // Turno del jugador 
            pAP += pr;
            cout << "You win the roll! AP = " << pAP << "\n";

            // Acción única del jugador
            cout << "\nHP " << pHp << " vs " << eHp 
                      << " | AP = " << pAP << "\n"
                      << "0) Skip\n1) Basic Attack (1AP, 5 dmg)\n";
            int opt = 2;
            vector<int> mapIdx;
            for (size_t i = 0; i < skills.size(); ++i) {
                auto &s = skills[i];
                if (s.typeID < 0 || s.typeID == player.typeID) {
                    int base = (s.name == "Rejuvenate" ? -10 : s.cost * 2);
                    cout << opt << ") " << s.name 
                              << " (" << s.cost << " AP, "
                              << (base < 0 
                                  ? to_string(-base) + " HP" 
                                  : to_string(base) + " dmg")
                              << ")\n";
                    mapIdx.push_back((int)i);
                    ++opt;
                }
            }
            cout << "Action: ";
            int ch = getIntInput(0, opt - 1);
            bool attacked = false;

            if (ch == 1 && pAP >= 1) {
                // Basic Attack
                pAP -= 1; attacked = true;
                int dmg = 5;
                float mult = getTypeMultiplier(player.typeID, enemy.typeID);
                dmg = int(dmg * mult);
                float totalDmg = dmg * (1 + eq.dmgPct);
                if (rand() % 100 < dodgeBase + int(eq.dodgePct * 100)) {
                    cout << "Enemy dodged your Basic Attack!\n";
                } else {
                    eHp -= int(totalDmg);
                    cout << "You hit for " << int(totalDmg)
                              << (mult > 1.0f ? " (super effective)" : "")
                              << "!\n";
                }
            }
            else if (ch >= 2) {
                // Skill o Rejuvenate
                auto &s = skills[mapIdx[ch-2]];
                if (pAP >= s.cost) {
                    pAP -= s.cost; attacked = true;
                    if (s.name == "Rejuvenate") {
                        pHp += 10;
                        cout << "You used Rejuvenate and healed 10 HP!\n";
                    } else {
                        int dmg = s.cost * 2;
                        float mult = getTypeMultiplier(player.typeID, enemy.typeID);
                        dmg = int(dmg * mult);
                        float totalDmg = dmg * (1 + eq.dmgPct);
                        if (rand() % 100 < dodgeBase + int(eq.dodgePct * 100)) {
                            cout << "Enemy dodged " << s.name << "!\n";
                        } else {
                            eHp -= int(totalDmg);
                            cout << s.name << " deals " << int(totalDmg)
                                      << (mult > 1.0f ? " (super effective)" : "")
                                      << "!\n";
                        }
                    }
                } else {
                    cout << "Not enough AP for " << s.name << "!\n";
                }
            } else {
                cout << "You skip your turn.\n";
            }

            // Reducir duración del objeto si atacó
            if (eq.duration > 0 && attacked) {
                eq.duration--;
                if (eq.duration == 0)
                    cout << "YOUR EQUIPPED ITEM BROKE!\n";
            }
        }
        else if (er > pr) {
            // Turno del enemigo 
            eAP += er;
            cout << "Enemy wins roll! Enemy AP = " << eAP << "\n";

            // Construir lista de acciones válidas
            struct Action { string name; int cost; bool isHeal; };
            vector<Action> enemyActions;
            enemyActions.push_back({"Basic Attack", 1, false});
            enemyActions.push_back({"Rejuvenate", 7, true});
            for (auto &s : skills) {
                if ((s.typeID < 0 || s.typeID == enemy.typeID)
                    && s.name != "Basic Attack"
                    && s.name != "Rejuvenate") {
                    enemyActions.push_back({s.name, s.cost, false});
                }
            }
            // Filtrar por coste
            vector<Action> usable;
            for (auto &a : enemyActions)
                if (a.cost <= eAP) usable.push_back(a);

            if (usable.empty()) {
                cout << "Enemy skips its turn.\n";
            } else {
                // Elegir y ejecutar
                Action act = usable[rand() % usable.size()];
                eAP -= act.cost;
                if (act.isHeal) {
                    eHp += 10;
                    cout << "Enemy uses " << act.name 
                              << " and heals 10 HP!\n";
                } else {
                    int dmg = (act.name == "Basic Attack") ? 5 : act.cost * 2;
                    float mult = getTypeMultiplier(enemy.typeID, player.typeID);
                    dmg = int(dmg * mult);
                    float totalDmg = dmg * (1 + eq.dmgPct);
                    if (rand() % 100 < dodgeBase + int(eq.dodgePct * 100)) {
                        cout << "You dodged the enemy's " << act.name << "!\n";
                    } else {
                        pHp -= int(totalDmg);
                        cout << "Enemy uses " << act.name 
                                  << " and deals " << int(totalDmg)
                                  << (mult > 1.0f ? " (super effective)" : "")
                                  << "!\n";
                    }
                }
            }
        }
        else {
            cout << "Tie! No AP gained.\n";
        }
    }

    // Resultado final
    cout << "\n=== Battle Over ===\n";
    if (pHp > 0) {
        cout << "*** You Win! ***\n";
        int gained = rand() % 11;
        cout << "EXP+" << gained << "\n";
        addUserExp(username, gained);
        addRandomItem();
    } else {
        cout << "*** You Lose... ***\n";
    }

    // Actualizar inventario según el objeto equipado 
    if (eq.invIndex >= 0) {
        auto &invRef = const_cast<vector<Item>&>(getInventory());
        if (eq.duration > 0) {
            invRef[eq.invIndex].duration = eq.duration;
            saveInventory(username);
            cout << eq.name << " has " << eq.duration
                      << " turns remaining in your inventory.\n";
        } else {
            invRef.erase(invRef.begin() + eq.invIndex);
            saveInventory(username);
        }
    }
}
