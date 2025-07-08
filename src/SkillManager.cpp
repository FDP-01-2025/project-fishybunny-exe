#include "SkillManager.h"
#include "Utils.h"
#include <iostream>
#include <vector>
using namespace std;

static vector<Skill> skills;

void loadSkills() { // Lista de habilidades del juego
    skills = {
// Genéricas:
        {"Basic Attack",1,-1,false}, {"Guard Stance",1,-1,false},
        {"Adrenaline Rush",5,-1,false},{"Battle Cry",4,-1,false},
//Por tipo:
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
        {"Rock Throw",3,17,false},   {"Boulder Crush",6,17,true}
    };
    // Nueva habilidad de curación universal
    skills.push_back({"Rejuvenate",7,-1,true});  // 7 AP, cura 10 HP, usable por todos
}

const vector<Skill>& getAllSkills() { // Devuelve todas las habilidades (para solo lectura)
    return skills;
}

void showSkills() { // Muestra todas las habilidades en pantalla
    cout << "\nAvailable Skills:\n";
    for (size_t i = 0; i < skills.size(); ++i) {
        auto &s = skills[i]; // Referencia a la habilidad actual
        cout << i+1 << ") " 
                  << s.name  // Nombre
                  << " (Cost " << s.cost  //Costo en puntos
                  << (s.special ? ", Special" : "")  // Si es especial, lo indica
                  << ", Type " 
                  << (s.typeID>=0?getTypeName(s.typeID):"Gen") //Nombre del tipo
                  << ")\n";
    }
}
