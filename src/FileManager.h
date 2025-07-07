#ifndef FILEMANAGER_H
#define FILEMANAGER_H

#include <string>
#include <vector>
using namespace std;
bool readFileLines(const string &path, vector<string> &lines);
bool writeFileLines(const string &path, const vector<string> &lines);

#endif