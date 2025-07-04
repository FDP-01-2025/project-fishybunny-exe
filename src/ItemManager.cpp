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

// Predefined items
static const std::vector<Item> ALL_ITEMS = {
    {"Rusted Longsword",20}, {"Ashen Warblade",15}, {"Bone Cleaver",10},
    {"Serpent’s Rapier",12}, {"Sunforged Greatsword",8}, {"Frostbrand Axe",10},
    {"Thunderstrike Mace",5}, {"Mercurial Dagger",12}, {"Draconic Halberd",7},
    {"Wraithblade",10}
};