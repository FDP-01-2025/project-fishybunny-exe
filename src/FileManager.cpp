#include "FileManager.h"
#include <fstream>
using namespace std;
bool readFileLines(const string &path, vector<string> &lines)
{
    ifstream in(path);
    if (!in.is_open())
        return false;
    string line;
    while (getline(in, line))
        lines.push_back(line);
    in.close();
    return true;
}

bool writeFileLines(const string &path, const vector<string> &lines)
{
    ofstream out(path);
    if (!out.is_open())
        return false;
    for (auto &l : lines)
        out << l << "\n";
    out.close();
    return true;
}