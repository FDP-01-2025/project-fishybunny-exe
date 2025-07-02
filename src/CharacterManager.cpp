#include "CharacterManager.h" //incluimos las librerias creadas
#include "FileManager.h"
#include "Utils.h"
#include <iostream>
#include <vector>
#include <string>

using namespace std;

static vector<Character> chars; // Lista de personajes que tiene el usuario
static string curUser;          // nombre del usuario actual
const int MAX_CH = 5;           // maximo de personajes que puede tener el usuario

// carga los personajes desde un archivo de texto
void loadCharacters(const string &user)
{
    curUser = user;       // establecer el usuario actual
    chars.clear();        // limpiar la lista de personajes
    vector<string> lines; // almacena las lineas del archivo

    // lee las lineas que tiene el usuario en su archivo
    if (readFileLines(user + "_chars.txt", lines))
    {
        for (auto &l : lines)
        {
            if (l.empty())
                continue;

            // divide automaticamente cada linea en partes separadas por comas
            auto p = splitString(l, ',');
            if (p.size() != 4)
                continue;

            // crea un personaje con los datos leidos
            Character c;
            c.name = p[0];
            c.level = stoi(p[1]);
            c.typeID = stoi(p[2]);
            c.exp = stoi(p[3]);
            chars.push_back(c);
        }
    }
}
// guarda los personajes del usuario actual en un archivo de texto
void saveCharacters(const std::string &user)
{
    std::vector<std::string> lines;
    for (auto &c : chars)
    {
        // convierte cada personaje a una linea de texto separada
        lines.push_back(
            c.name + "," +
            std::to_string(c.level) + "," +
            std::to_string(c.typeID) + "," +
            std::to_string(c.exp));
    }
