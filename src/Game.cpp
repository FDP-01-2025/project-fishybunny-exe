#include "Game.h"
#include "CharacterManager.h"
#include "ItemManager.h"
#include "SkillManager.h"
#include "ProfileManager.h"
#include "Utils.h"
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;
void startGame(const string &username) {
    srand((unsigned)time(nullptr));
    cout << "\n=== Start Battle ===\n";

    // Cargar datos
    int userLevel      = getUserLevel(username);
    auto defaultChars  = getDefaultCharactersUpToLevel(userLevel);
    loadCharacters(username);
    auto customChars   = getCharacters();
    loadSkills();

    // Menu personajes propios
    cout << "1) Default Characters (" << defaultChars.size() << " unlocked)\n"
              << "2) Your Created Characters (" << customChars.size() << ")\n"
              << "3) Back to Menu\n"
              << "Choose: ";
    int pc = getIntInput(1,3);
    if (pc == 3) return;

    vector<Character>* pool;