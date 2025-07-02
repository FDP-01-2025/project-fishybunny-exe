#ifndef MENU_H
#define MENU_H

#include <string>

// Interfaz del menú
void showGameTitle();
void showMainMenu();
int selectMainOption();

// Gestión de usuarios (ahora también accesible desde el menú principal)
void manageUsers();

// Gestión de personajes
void createCharacterMenu(const std::string &username);

// Ver reglas
void showRules();

#endif 