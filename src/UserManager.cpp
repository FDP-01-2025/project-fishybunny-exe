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