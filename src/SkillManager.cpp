#include "SkillManager.h"
#include "Utils.h"
#include <iostream>
#include <vector>
using namespace std;
static vector<Skill> skills;

void loadSkills() {
    skills = {
        {"Crimson Slash",3,0,false}, {"Ember Strike",5,0,true},
        {"Aqua Shield",4,1,false},   {"Tidal Wave",7,1,true},
        {"Earthen Bash",3,2,false},  {"Stonefist",6,2,true},
        {"Gale Dancer",4,3,false},   {"Tempest Call",8,3,true},
        {"Spark Lance",4,4,false},   {"Thunder Roar",7,4,true},
        {"Frostbite",4,5,false},     {"Glacial Spike",6,5,true},
        {"Iron Wall",5,6,false},     {"Metal Storm",8,6,true},
        {"Savage Claw",3,7,false},   {"Beast Roar",6,7,true},
        {"Mystic Orb",4,8,false},    {"Arcane Blast",7,8,true},
        {"Soul Drain",5,9,false},    {"Wraith Touch",8,9,true},
        {"Divine Light",5,10,false}, {"Holy Judgment",9,10,true},