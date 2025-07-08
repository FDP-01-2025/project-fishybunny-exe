#include "FileManager.h"
#include <fstream>
using namespace std;
bool readFileLines(const string &path, vector<string> &lines) //Lee Archivo y guarda
{
    ifstream in(path); // Abre el archivo
    if (!in.is_open()) //Verifica que este abierto
        return false;
    string line;
    while (getline(in, line))
        lines.push_back(line); //Agrega cada linea
    in.close();
    return true;
}

bool writeFileLines(const string &path, const vector<string> &lines) // Escribe en el archivo y guarda
{
    ofstream out(path);// Abre el archivo
    if (!out.is_open())//Verifica que este abierto
        return false;
    for (auto &l : lines)
        out << l << "\n";  // Escribe la línea en el archivo
    out.close();
    return true;
}