#ifndef ITEMMANAGER_H
#define ITEMMANAGER_H

#include <string>
#include <vector>

struct Item {
    std::string name;
    int duration;
};

void loadInventory(const std::string &user);
void saveInventory(const std::string &user);
void showInventory();
bool addRandomItem();
void deleteItem(int idx);
void showInventoryAndLevel(const std::string &user);
const std::vector<Item>& getInventory();

#endif