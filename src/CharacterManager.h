#ifndef CHARACTERMANAGER_H // comprueba si el la libreria esta definida
#define CHARACTERMANAGER_H // definimos la libreria

#include <string>
#include <vector> //abrimos la libreria de los arrays
using namespace std;
// agregamos las nuevas variables que va a tener el struct character
struct Character
{
    string name;
    int level;
    int typeID;
    int exp;
};
// definimos las nuevas funciones de carga, guardado, mostrar, seleccionar, crear y borrar
void loadCharacters(const string &user);
void saveCharacters(const string &user);
void showCharacters();
int selectCharacter();
int createCharacter(const string &name, int typeID);
void deleteCharacter(int idx);
const vector<Character> &getCharacters();

#endif // terminamos la comprobacion de la libreria
