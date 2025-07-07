#ifndef MENU_H
#define MENU_H
#include <string>
using namespace std;
// Interfaz del menú
void showUserMenu();
int selectUserMenuOption();
// Gestión de usuarios (ahora también accesible desde el menú principal)
void createUserSubMenu();
void deleteUserSubMenu();
bool chooseUserSubMenu(string &outUsername);

// Menu de juego
void showGameTitle();
void showGameMenu();
int selectGameOption();
// Gestión de personajes
void manageCharactersSubMenu(const string &username);

// Ver reglas
void showRules();            // <-- añadida
void showRulesSubMenu();

#endif 
