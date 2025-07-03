#include "Menu.h"
#include "Utils.h"
#include "UserManager.h"
#include "CharacterManager.h"
#include <iostream>
#include <string>
using namespace std;
// Muestra el título del juego
void showGameTitle() {
    cout << "=== DEADLY ROLL ===\n";
    cout << "A turn-based dice combat game\n";
}

// Menú principal, con opción de gestionar usuarios
void showMainMenu() {
    cout << "\nMain Menu:\n"
              << "1) Play Game\n"
              << "2) Manage Characters\n"
              << "3) Manage Users\n"
              << "4) View Rules\n"
              << "5) Inventory & Level\n"
              << "6) Exit\n"
              << "Choose: ";
}

// Validación de elección principal 1–6
int selectMainOption() {
    return getIntInput(1,6);
}

// Gestión de usuarios desde el menú principal
void manageUsers() {
    while (true) {
        showUsers();
        cout << "\nUser Management:\n"
                  << "1) Create User\n"
                  << "2) Delete User\n"
                  << "3) Back\n"
                  << "Choose: ";
        int c = getIntInput(1,3);
        if (c == 1) {
            cout << "Enter new user name: ";
            string name;
            getline(cin, name);
            createUser(name);
        } else if (c == 2) {
            showUsers();
            cout << "Select user # to delete: ";
            int idx = getIntInput(1, (int)getUsers().size()) - 1;
            deleteUser(idx);
        } else {
            break;
        }
    }
}

// Gestión de personajes (sin cambios)
void createCharacterMenu(const string &username) {
    loadCharacters(username);
    cout << "\nCharacter Management:\n";

    }