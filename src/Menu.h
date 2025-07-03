#ifndef MENU_H
#define MENU_H
#include <string>
using namespace std;
// Interfaz del menú
void showGameTitle();
void showMainMenu();
int selectMainOption();

// Gestión de usuarios (ahora también accesible desde el menú principal)
void manageUsers();

// Gestión de personajes
void createCharacterMenu(const string &username);

// Ver reglas
void showRules();

#endif 