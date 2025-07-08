#ifndef SKILLMANAGER_H
#define SKILLMANAGER_H

#include <string>
#include <vector>
using namespace std;

struct Skill {
    string name; //Nombre
    int cost; //Costo
    int typeID; //Tipo
    bool special; //Indica si es especial
};

void loadSkills(); //Carga habilidades
const vector<Skill>& getAllSkills(); // Devuelve todas las habilidades (solo lectura)
void showSkills(); //Muestra las habilidades


#endif



