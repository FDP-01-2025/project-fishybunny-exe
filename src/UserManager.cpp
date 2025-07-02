#include "UserManager.h"
#include "FileManager.h"
#include "Utils.h"
#include <iostream>
#include <vector>
#include <string>

static std::vector<std::string> users;
static const std::string USERS_FILE = "users.txt";

void loadUsers() {
    users.clear();
    std::vector<std::string> lines;
    if (readFileLines(USERS_FILE, lines)) {
        for (auto &l : lines)
            if (!l.empty())
                users.push_back(l);
    }
}

void saveUsers() {
    writeFileLines(USERS_FILE, users);
}

void showUsers() {
    std::cout << "\nUsers:\n";
    for (size_t i = 0; i < users.size(); ++i)
        std::cout << i+1 << ") " << users[i] << "\n";
}

int selectUser() {
    if (users.empty()) return -1;
    showUsers();
    std::cout << "Select user (#) or 0 to manage: ";
    int c = getIntInput(0, (int)users.size());
    return c ? c - 1 : -1;
}

int createUser(const std::string &name) {
    if (users.size() >= 3) {
        std::cout << "Max 3 users.\n";
        return -1;
    }
    users.push_back(name);
    saveUsers();
    return (int)users.size() - 1;
}

void deleteUser(int idx) {
    if (idx >= 0 && idx < (int)users.size()) {
        users.erase(users.begin() + idx);
        saveUsers();
    }
}

std::string getUserName(int idx) {
    return (idx >= 0 && idx < (int)users.size()) ? users[idx] : "";
}

const std::vector<std::string>& getUsers() {