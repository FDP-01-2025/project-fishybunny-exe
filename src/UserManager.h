#ifndef USERMANAGER_H
#define USERMANAGER_H

#include <string>
#include <vector>

struct User {
    std::string nickname;
};

#endif

// ===== src/SkillManager.h =====
#ifndef SKILLMANAGER_H
#define SKILLMANAGER_H

#include <string>
#include <vector>

struct Skill {
    std::string name;
    int power;
};

#endif