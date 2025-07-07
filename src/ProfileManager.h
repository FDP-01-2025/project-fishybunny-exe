#ifndef PROFILEMANAGER_H//inicio de comprobacion si existe una libreria ya creada con ese nombre
#define PROFILEMANAGER_H//definir la libreria
//incluimos las librerias que queremos ocupar en el codigo
#include <string>
#include <vector>
#include "CharacterManager.h"
using namespace std;
// Perfil de usuario (nivel y EXP)
int getUserLevel(const string &username);
int getUserExp(const string &username);
bool addUserExp(const string &username, int expGained);

// Personajes predeterminados desbloqueados por nivel
vector<Character> getDefaultCharactersUpToLevel(int level);


#endif //terminamos la comprobacion