#ifndef USERMANAGER_H
#define USERMANAGER_H
#include <string>

struct User {
    std::string nickname;
};

class UserManager {
public:
    void createUser(const User& user);
};

#endif