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