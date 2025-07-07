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
    // Carga inventario para uso posterior
    loadInventory(username);

    // resto del combate 
}
