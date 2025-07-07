#include <iostream>
#include "Menu.h"
#include "UserManager.h"
#include "CharacterManager.h"
#include "ItemManager.h"
#include "Game.h"
#include "Utils.h"
using namespace std;
// Ejecuta todo el flujo del menú de juego para un usuario dado
void runGameSession(const string &username) {
    // Carga datos del usuario
    loadCharacters(username);
    loadInventory(username);
    bool backToUserMenu = false;

    while (!backToUserMenu) {
        showGameTitle();
        cout << "Welcome, " << username << "!\n";  // <-- Welcome tras el título
        showGameMenu();
        int gopt = selectGameOption();
        switch (gopt) {
            case 1:
                startGame(username);
                break;
            case 2:
                manageCharactersSubMenu(username);
                break;
            case 3:
                showRulesSubMenu();
                break;
            case 4:
                showInventoryAndLevel(username);
                break;
            case 5:
                backToUserMenu = true;
                break;
            default:
                cout << "Invalid option.\n";
        }
    }

    // Guardar al volver al menú de usuarios
    saveCharacters(username);
    saveInventory(username);
    saveUsers();
}

int main() {
    loadUsers();

    while (true) {
        // 1) Menú de Usuarios
        showUserMenu();
        int opt = selectUserMenuOption();

        if (opt == 1) {
            // Crear usuario y entrar de inmediato
            cout << "Enter new user name: ";
            string name;
            getline(cin, name);
            int idx = createUser(name);
            if (idx >= 0) {
                saveUsers();
                runGameSession(name);
            }
        }
        else if (opt == 2) {
            // Borrar usuario
            deleteUserSubMenu();
        }
        else if (opt == 3) {
            // Elegir usuario y entrar
            string username;
            if (chooseUserSubMenu(username)) {
                runGameSession(username);
            }
        }
        else {
            // Salir del programa
            cout << "Exiting program. Goodbye!\n";
            break;
        }
    }

    return 0;
}
