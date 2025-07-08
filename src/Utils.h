#ifndef UTILS_H
#define UTILS_H

#include <string>
#include <vector>
using namespace std;
// Lee un entero entre min y max (incluidos), validando la entrada
int getIntInput(int min, int max);

// Lee un único carácter
char getCharInput();

// Rompe una cadena en partes según un delimitador
vector<string> splitString(const string &s, char delimiter);

// Multiplicador de tipos (para futuro uso en daño elemental)
float getTypeMultiplier(int atkType, int defType);

// Nombre de tipo a partir del ID
string getTypeName(int typeID);

#endif
