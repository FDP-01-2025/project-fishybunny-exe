#ifndef CHARACTER_MANAGER_H // comprobamos si esta definida la libreria
#define CHARACTER_MANAGER_H // definimos la libreria
#include <string>
using namespace std;
// creamos el conjunto de variables para el personaje
struct Character
{
    string name;
    int level;
};
// creamos una clase para el manejo de personajes
class CharacterManager
{
public:                                               // esto para que sea accesible desde afuera de la clase
    void createCharacter(const Character &character); // declaramos la funcion para crear un personaje
};

#endif // terminamos nuestro if de la libreria