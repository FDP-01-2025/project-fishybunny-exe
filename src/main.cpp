#include <iostream>
#include "Menu.h"
#include "UserManager.h"
#include "CharacterManager.h"
#include "ItemManager.h"
#include "Game.h"
#include "Utils.h"
using namespace std;
int main() {
    // Antes de llegar al menú principal, siempre cargamos usuarios
    loadUsers();

    string username;
    int userIndex = -1;
    // Si no hay usuarios, forzamos a gestionar usuarios
    if (getUsers().empty()) {
        cout << "No users found. Please create one.\n";
        manageUsers();
    }

    // Selección inicial de usuario
    while (true) {
        showUsers();
        cout << "Select user (#): ";
        userIndex = getIntInput(1, (int)getUsers().size()) - 1;
        if (userIndex >= 0) break;
    }
    username = getUserName(userIndex);
    cout << "\nWelcome, " << username << "!\n";

    // Carga inicial de datos del usuario
    loadCharacters(username);
    loadInventory(username);

    // Menú principal
    showGameTitle();
    bool exitGame = false;
    while (!exitGame) {
        showMainMenu();
        int choice = selectMainOption();
        switch (choice) {
            case 1:
                startGame(username);
                break;
            case 2:
                createCharacterMenu(username);
                break;
            case 3:
                manageUsers();
                // Tras gestionar usuarios, recargamos lista y re-seleccionamos uno
                loadUsers();
                showUsers();
                cout << "Select user (#): ";
                userIndex = getIntInput(1, (int)getUsers().size()) - 1;
                username = getUserName(userIndex);
                cout << "\nSwitched to user: " << username << "!\n";
                // Recarga sus datos
                loadCharacters(username);
                loadInventory(username);
                break;
            case 4:
                showRules();
                break;
            case 5:
                showInventoryAndLevel(username);
                break;
            case 6:
                exitGame = true;
                break;
            default:
                cout << "Invalid option.\n";
        }
    }

    // Guardar todo al salir
    saveCharacters(username);
    saveInventory(username);
    saveUsers();
    cout << "Goodbye!" << endl;
    return 0;
}
