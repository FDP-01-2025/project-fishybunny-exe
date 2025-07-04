#include "CharacterManager.h" //incluimos las librerias creadas
#include "File_Manager.h"
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
void saveCharacters(const string &user)
{
    vector<string> lines;
    for (auto &c : chars)
    {
        // convierte cada personaje a una linea de texto separada
        lines.push_back(
            c.name + "," +
            to_string(c.level) + "," +
            to_string(c.typeID) + "," +
            to_string(c.exp));
    }
    writeFileLines(user + "_chars.txt", lines);
}
//creamos a la funcion para que nos muestre los personajes
void showCharacters()
{
    cout << "\nYour Characters:\n";
    if (chars.empty())
    {
        cout << "  (none)\n";
        return;
    }
    for (size_t i = 0; i < chars.size(); ++i)
    {
        auto &c = chars[i];
        cout
            << "  " << i + 1 << ") " << c.name
            << " (Type " << c.typeID
            << ") Lv." << c.level
            << " Exp:" << c.exp
            << "\n";
    }
}
//creamos a la funcion de la eleccion de personajes
int selectCharacter()
{
    if (chars.empty())
        return -1;
    showCharacters();
    cout << "Select # or 0 to cancel: ";
    int c = getIntInput(0, (int)chars.size());
    return c ? c - 1 : -1;
}
//creamos la funcion para que el usuario cree sus propios personajes
int createCharacter(const string &name, int typeID)
{
    if (chars.size() >= MAX_CH)
    {
        cout << "Max 5 characters. Delete one first.\n";
        return -1;
    }
    chars.push_back({name, 1, typeID, 0});
    saveCharacters(curUser);
    return (int)chars.size() - 1;
}
//empezamos a crear la funcion para que el usuario pueda borrar a sus personajes
void deleteCharacter(int idx)
{
    if (idx >= 0 && idx < (int)chars.size()) {
        chars.erase(chars.begin() + idx);
        saveCharacters(curUser);
    }
}

const vector<Character>& getCharacters() {
    return chars;
}//correccion en la funcion de borrar personajes
