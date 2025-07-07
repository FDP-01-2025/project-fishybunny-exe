#include "ItemManager.h"
#include "FileManager.h"
#include "Utils.h"
#include "ProfileManager.h"
#include <iostream>
#include <vector>
#include <string>
using namespace std;

static vector<Item> inventory;
static string invUser;
const int MAX_INV = 10;

// Lista de items en el juego
static const vector<Item> ALL_ITEMS = {
    {"Rusted Longsword", 20}, {"Ashen Warblade", 15}, {"Bone Cleaver", 10}, {"Serpent’s Rapier", 12}, {"Sunforged Greatsword", 8}, {"Frostbrand Axe", 10}, {"Thunderstrike Mace", 5}, {"Mercurial Dagger", 12}, {"Draconic Halberd", 7}, {"Wraithblade", 10}};

void loadInventory(const string &user) // Carga el inventario del usuario desde un archivo
{
    invUser = user;
    inventory.clear();
    vector<string> lines;
    if (readFileLines(user + "_inv.txt", lines) && !lines.empty())
    {
        auto parts = splitString(lines[0], ';');
        for (auto &p : parts)
        {
            auto f = splitString(p, ',');
            if (f.size() != 2)
                continue;
            inventory.push_back({f[0], std::stoi(f[1])});
        }
    }
}

void saveInventory(const string &user) // Se almacena el inventario del usuario en su archivo
{
    string line;
    for (size_t i = 0; i < inventory.size(); ++i)
    {
        line += inventory[i].name + "," + std::to_string(inventory[i].duration);
        if (i + 1 < inventory.size())
            line += ";";
    }
    writeFileLines(user + "_inv.txt", {line});
}

void showInventory() // Muestra en pantalla el inventario del usuario
{
    cout << "\nInventory for " << invUser << ":\n";
    for (size_t i = 0; i < inventory.size(); ++i)
    {
        cout << i + 1 << ") "
                  << inventory[i].name
                  << " (" << inventory[i].duration << " turns)\n";
    }
}
bool addRandomItem() // Añade un item random
{
    if (inventory.size() >= MAX_INV)
    {
        std::cout << "Inventory full. Delete items first.\n";
        return false;
    }
    int idx = rand() % ALL_ITEMS.size();
    inventory.push_back(ALL_ITEMS[idx]);
    saveInventory(invUser);
    cout << "Obtained: " << ALL_ITEMS[idx].name << "!\n";
    return true;
}

void deleteItem(int idx) // Elimina el item
{
    if (idx >= 0 && idx < (int)inventory.size())
    {
        inventory.erase(inventory.begin() + idx);
        saveInventory(invUser);
    }
}

void showInventoryAndLevel(const string &user) // Enseña el inventario y el nivel
{
    showInventory();
    int lvl = getUserLevel(user);
    int exp = getUserExp(user);
    int needed = lvl * 10 - exp;
    cout << "\nLevel: " << lvl
              << " | EXP: " << exp
              << " (" << needed << " to next level)\n";
}
const vector<Item> &getInventory()
{
    return inventory;
}