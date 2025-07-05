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
 if (pc == 2) {
        if (customChars.empty()) {
            std::cout << "You have no created characters. Please create one first.\n";
            return;
        }
        pool = &customChars;
    } else {
        pool = &defaultChars;
    }

    // Listado y selección
    cout << "\nSelect your character:\n";
    for (size_t i = 0; i < pool->size(); ++i) {
        auto &c = (*pool)[i];
        cout << "  " << i+1 << ") "
                  << c.name << " (" << getTypeName(c.typeID) << ")\n";
    }
    cout << "Choose: ";
    int idx = getIntInput(1, (int)pool->size()) - 1;
    Character player = (*pool)[idx];
    cout << "\nYou selected " << player.name << "!\n";

    // resto del combate 


}
