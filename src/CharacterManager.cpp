#include "CharacterManager.h" //abrimos la libreria que creamos
#include <iostream>
using namespace std;

// Abrimos nuestra clase de manejo de personajes en el apartado de crear un personaje. definiewndo nuestra variable constante character y Character
void CharacterManager::createCharacter(const Character &character)
{
    cout << "Personaje " << character.name
         << " creado con nivel " << character.level << ".\n";
    // se imprime el nombre y nivel del personaje creado
}
