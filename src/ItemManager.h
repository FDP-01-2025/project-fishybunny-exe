#ifndef ITEMMANAGER_H
#define ITEMMANAGER_H

#include <string>
#include <vector>
using namespace std;

struct Item
{
    std::string name;
    int duration;
};

void loadInventory(const string &user);
void saveInventory(const string &user);
void showInventory();
bool addRandomItem();
void deleteItem(int idx);
void showInventoryAndLevel(const string &user);
const vector<Item> &getInventory();

#endif