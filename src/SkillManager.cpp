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
        {"Shadow Veil",4,11,false},  {"Dark Eclipse",8,11,true},
        {"Nature’s Grasp",4,12,false},{"Forest’s Wrath",7,12,true},
        {"Poison Fang",3,13,false},  {"Venom Burst",6,13,true},
        {"Mind Spike",4,14,false},   {"Psychic Storm",8,14,true},
        {"Dragon’s Claw",5,15,false},{"Drake Fury",9,15,true},
        {"Quick Jab",2,16,false},    {"Perfect Strike",5,16,true},
        {"Rock Throw",3,17,false},   {"Boulder Crush",6,17,true},
        // Genéricas:
        {"Basic Attack",1,-1,false}, {"Guard Stance",1,-1,false},
        {"Adrenaline Rush",5,-1,false},{"Battle Cry",4,-1,false}
    };
}

const vector<Skill>& getAllSkills() {
    return skills;
}

void showSkills() {
    cout << "\nAvailable Skills:\n";
    for (size_t i = 0; i < skills.size(); ++i) {
        auto &s = skills[i];
        cout << i+1 << ") " 
                  << s.name 
                  << " (Cost " << s.cost 
                  << (s.special ? ", Special" : "") 
                  << ", Type " << (s.typeID>=0?std::to_string(s.typeID):"Gen")
                  << ")\n";
    }