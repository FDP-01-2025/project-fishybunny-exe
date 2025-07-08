#ifndef FILEMANAGER_H
#define FILEMANAGER_H

#include <string>
#include <vector>
using namespace std;
bool readFileLines(const string &path, vector<string> &lines); //Lee Archivo y guarda
bool writeFileLines(const string &path, const vector<string> &lines); // Escribe en el archivo y guarda

#endif