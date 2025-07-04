//incluimos todas las librerias a usar
#include "ProfileManager.h"
#include "File_Manager.h"
#include "Utils.h"
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

static const string EXT = "_profile.txt";//hacemos que EXT una varibale constante estatica que almacene la extension de nuestro archivo de texto
// Lista completa de personajes por defecto
static const vector<Character> ALL_DEFAULT_CHARS = {
    {"Footman",1,16,0},{"Pyromancer",1,0,0},{"Hydromancer",1,1,0},
    {"Earthshaper",1,2,0},{"Aeromancer",1,3,0},{"Electroknight",1,4,0},
    {"Cryomancer",1,5,0},{"Iron Golem",1,6,0},{"Beastmaster",1,7,0},
    {"Mystic Sage",1,8,0},{"Necromancer",1,9,0},{"Cleric",1,10,0},
    {"Shadowblade",1,11,0},{"Druid",1,12,0},{"Venomancer",1,13,0},
    {"Psychic Monk",1,14,0},{"Dragon Knight",1,15,0},{"Rockguard",1,17,0}
};

// Carga perfil desde archivo o inicializa a nivel 1, EXP 0
static void loadProfile(const string &user, int &lvl, int &exp) {
    vector<string> lines;
    if (readFileLines(user + EXT, lines) && !lines.empty()) {
        auto parts = splitString(lines[0], ',');
        if (parts.size() == 2) {
            lvl = stoi(parts[0]);
            exp = stoi(parts[1]);
            return;
        }
    }