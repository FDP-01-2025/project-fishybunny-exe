#ifndef ITEMMANAGER_H
#define ITEMMANAGER_H

#include <string>
#include <vector>
using namespace std;

struct Item //Struct de item
{
    std::string name;
    int duration;
};

void loadInventory(const string &user); // Carga el inventario de un usuario
void saveInventory(const string &user);// Guarda el inventario del usuario
void showInventory(); //Muestra el inventario del usuario
bool addRandomItem(); // Agrega un ítem aleatorio al inventario
void deleteItem(int idx); //Elimina un item del inventario segun lo indicado
void showInventoryAndLevel(const string &user);  //Muestra inventario y nivel del usuario
const vector<Item> &getInventory(); //Acceso solo de lectura a todos los items del inventario

#endif