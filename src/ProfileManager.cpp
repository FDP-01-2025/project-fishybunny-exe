#include "ProfileManager.h"
#include "FileManager.h"
#include "Utils.h"
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

static const string EXT = "_profile.txt";  // Sufijo usado para almacenar perfiles

// Lista completa de personajes por defecto (nivel 1)
static const vector<Character> ALL_DEFAULT_CHARS = {
    {"Footman",1,16,0},{"Pyromancer",1,0,0},{"Hydromancer",1,1,0},
    {"Earthshaper",1,2,0},{"Aeromancer",1,3,0},{"Electroknight",1,4,0},
    {"Cryomancer",1,5,0},{"Iron Golem",1,6,0},{"Beastmaster",1,7,0},
    {"Mystic Sage",1,8,0},{"Necromancer",1,9,0},{"Cleric",1,10,0},
    {"Shadowblade",1,11,0},{"Druid",1,12,0},{"Venomancer",1,13,0},
    {"Psychic Monk",1,14,0},{"Dragon Knight",1,15,0},{"Rockguard",1,17,0}
};

// Carga el perfil del usuario desde un archivo.
// Si no existe o está malformado, se inicializa en nivel 1 con 0 EXP.
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
    lvl = 1;
    exp = 0;
    writeFileLines(user + EXT, { "1,0" });  // Guardar estado inicial
}

// Guarda el perfil del usuario (nivel y experiencia) en el archivo correspondiente
static void saveProfile(const string &user, int lvl, int exp) {
    writeFileLines(user + EXT, { to_string(lvl) + "," + to_string(exp) });
}

// Devuelve el nivel actual del usuario
int getUserLevel(const string &username) {
    int lvl, exp;
    loadProfile(username, lvl, exp);
    return lvl;
}

// Devuelve la experiencia actual del usuario
int getUserExp(const string &username) {
    int lvl, exp;
    loadProfile(username, lvl, exp);
    return exp;
}

// Añade experiencia al usuario y gestiona subida de nivel si corresponde
bool addUserExp(const string &username, int expGained) {
    int lvl, exp;
    loadProfile(username, lvl, exp);
    exp += expGained;
    bool leveledUp = false;

    // Mientras la experiencia acumulada sea suficiente, subir de nivel
    while (exp >= lvl * 10) {
        exp -= lvl * 10;
        lvl++;
        leveledUp = true;
    }

    saveProfile(username, lvl, exp);
    
    if (leveledUp) {
        cout << "Reached level " << lvl << "!\n";
    }

    return leveledUp;
}

// Devuelve una lista de personajes desbloqueados según el nivel del usuario
vector<Character> getDefaultCharactersUpToLevel(int level) {
    size_t cnt = min((size_t)level, ALL_DEFAULT_CHARS.size());
    return { ALL_DEFAULT_CHARS.begin(), ALL_DEFAULT_CHARS.begin() + cnt };
}