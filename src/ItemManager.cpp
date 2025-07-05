#include "ItemManager.h"
#include "FileManager.h"
#include "Utils.h"
#include "ProfileManager.h"
#include <iostream>
#include <vector>
#include <string>

static std::vector<Item> inventory;
static std::string invUser;
const int MAX_INV = 10;

// Lista de items en el juego
static const std::vector<Item> ALL_ITEMS = {
    {"Rusted Longsword", 20}, {"Ashen Warblade", 15}, {"Bone Cleaver", 10}, {"Serpent’s Rapier", 12}, {"Sunforged Greatsword", 8}, {"Frostbrand Axe", 10}, {"Thunderstrike Mace", 5}, {"Mercurial Dagger", 12}, {"Draconic Halberd", 7}, {"Wraithblade", 10}};

void loadInventory(const std::string &user) //Carga el inventario del usuario desde un archivo
{
    invUser = user;
    inventory.clear();
    std::vector<std::string> lines;
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

void saveInventory(const std::string &user) //Se almacena el inventario del usuario en su archivo
{
    std::string line;
    for (size_t i = 0; i < inventory.size(); ++i)
    {
        line += inventory[i].name + "," + std::to_string(inventory[i].duration);
        if (i + 1 < inventory.size())
            line += ";";
    }
    writeFileLines(user + "_inv.txt", {line});
}

void showInventory() //Muestra en pantalla el inventario del usuario
{
    std::cout << "\nInventory for " << invUser << ":\n";
    for (size_t i = 0; i < inventory.size(); ++i)
    {
        std::cout << i + 1 << ") "
                  << inventory[i].name
                  << " (" << inventory[i].duration << " turns)\n";
    }}