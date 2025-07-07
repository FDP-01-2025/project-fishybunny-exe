#include "Menu.h"
#include "Utils.h"
#include "UserManager.h"
#include "CharacterManager.h"
#include <iostream>
#include <string>
#include <vector>
using namespace std;
// Muestra el menú de usuarios
void showUserMenu() {
    cout << "\n=== USER MENU ===\n"
              << "1) Create User\n"
              << "2) Delete User\n"
              << "3) Choose User\n"
              << "4) Back (Exit)\n"
              << "Choose: ";
}
int selectUserMenuOption() {
    return getIntInput(1,4);
}

void createUserSubMenu() {
    while (true) {
        cout << "\n--- CREATE USER ---\n"
                  << "1) Enter new user name\n"
                  << "2) Back\n"
                  << "Choose: ";
        int c = getIntInput(1,2);
        if (c == 1) {
            cout << "New user name: ";
            string name; getline(cin, name);
            createUser(name);
            saveUsers();
        } else break;
    }
}

void deleteUserSubMenu() {
    while (true) {
        showUsers();
        cout << "\n--- DELETE USER ---\n"
                  << "1) Select user to delete\n"
                  << "2) Back\n"
                  << "Choose: ";
        int c = getIntInput(1,2);
        if (c == 1) {
            showUsers();
            cout << "Delete user #: ";
            int idx = getIntInput(1, (int)getUsers().size()) - 1;
            deleteUser(idx);
            saveUsers();
        } else break;
    }
}

bool chooseUserSubMenu(string &outUsername) {
    while (true) {
        showUsers();
        cout << "\n--- CHOOSE USER ---\n"
                  << "1) Select user\n"
                  << "2) Back\n"
                  << "Choose: ";
        int c = getIntInput(1,2);
        if (c == 1) {
            showUsers();
            cout << "User #: ";
            int idx = getIntInput(1, (int)getUsers().size()) - 1;
            outUsername = getUserName(idx);
            return true;
        } else {
            return false;
        }
    }
}

// -------- Game Menu --------
void showGameTitle() {
    cout << "\n=== DEADLY ROLL ===\n";
}

void showGameMenu() {
    cout << "\n--- GAME MENU ---\n"
              << "1) Play Game\n"
              << "2) Manage Characters\n"
              << "3) View Rules\n"
              << "4) Inventory & Level\n"
              << "5) Back to User Menu\n"
              << "Choose: ";
}

int selectGameOption() {
    return getIntInput(1,5);
}
// Gestión de personajes
void manageCharactersSubMenu(const string &username) {
    while (true) {
        loadCharacters(username);
        cout << "\n--- CHARACTER MENU ---\n"
                  << "1) Create Character\n"
                  << "2) Delete Character\n"
                  << "3) Back\n"
                  << "Choose: ";
        int c = getIntInput(1,3);
        if (c == 1) {
            cout << "Enter character name: ";
            string name; getline(cin, name);
            // Mostrar tipos con nombres
            cout << "Available Types:\n";
            for (int t = 0; t < 18; ++t)
                cout << "  " << t << ") " << getTypeName(t) << "\n";
            cout << "Choose type #: ";
            int typeID = getIntInput(0,17);
            createCharacter(name, typeID);
            saveCharacters(username);
        } else if (c == 2) {
            showCharacters();
            cout << "Select # to delete (0 cancel): ";
            int idx = getIntInput(0, (int)getCharacters().size());
            if (idx > 0) {
                deleteCharacter(idx - 1);
                saveCharacters(username);
            }
        } else break;
    }
}

// Mostrar reglas
void showRules() {
    cout << "\n=== GAME RULES ===\n\n";

    // 1) Tipos
    cout << "Types:\n";
    for (int t = 0; t < 18; ++t)
        cout << "  " << t << ") " << getTypeName(t) << "\n";
    cout << "\n";

    // 2) Matriz de ventajas/debilidades
    cout << "Type Matchups (Attacker > Defender):\n";
    cout << "  Fire > Ice,     Ice > Water,    Water > Fire\n";
    cout << "  Earth > Lightning, Lightning > Water, Water > Fire\n";
    cout << "  Air > Earth,    Rock > Air,     Earth > Lightning\n";
    cout << "  Metal > Beast,  Beast > Psychic, Psychic > Holy\n";
    cout << "  Holy > Undead,  Undead > Mystic, Mystic > Poison\n";
    cout << "  Poison > Nature, Nature > Rock, Rock > Metal\n\n";
    cout << "Damage x2 if advantage, x0.5 if disadvantage.\n\n";

    // 3) Personajes predeterminados
    vector<pair<string,int>> defs = {
        {"Footman",16},{"Pyromancer",0},{"Hydromancer",1},{"Earthshaper",2},
        {"Aeromancer",3},{"Electroknight",4},{"Cryomancer",5},{"Iron Golem",6},
        {"Beastmaster",7},{"Mystic Sage",8},{"Necromancer",9},{"Cleric",10},
        {"Shadowblade",11},{"Druid",12},{"Venomancer",13},{"Psychic Monk",14},
        {"Dragon Knight",15},{"Rockguard",17}
    };
    cout << "Default Characters:\n";
    for (auto &d : defs)
        cout << "  " << d.first << " (" << getTypeName(d.second) << ")\n";
    cout << "\n";

    // 4) Objetos especiales (porcentajes)
    struct ObjInfo { string name; int dur; float dmgPct, dodgePct; };
    vector<ObjInfo> objs = {
        {"Rusted Longsword",20, 0.10f, 0.0f},
        {"Ashen Warblade",15, 0.20f, 0.0f},
        {"Bone Cleaver",10, 0.30f, 0.0f},
        {"Serpent’s Rapier",12, 0.0f, 0.10f},
        {"Sunforged Greatsword",8,  0.25f, 0.0f},
        {"Frostbrand Axe",10,       0.0f, 0.15f},
        {"Thunderstrike Mace",5,    0.40f, 0.0f},
        {"Mercurial Dagger",12,     0.05f, 0.05f},
        {"Draconic Halberd",7,      0.50f, 0.0f},
        {"Wraithblade",10,          0.0f, 0.20f}
    };
    cout << "Special Items (Duration, +% Damage, +% Dodge):\n";
    for (auto &o : objs) {
        cout << "  " << o.name
                  << " (" << o.dur << " turns): "
                  << "+" << int(o.dmgPct*100) << "% dmg, "
                  << "+" << int(o.dodgePct*100) << "% dodge\n";
    }
    cout << endl;
}

void showRulesSubMenu() {
    showRules();
    cout << "\nPress ENTER to go back...";
    cin.get();
}
