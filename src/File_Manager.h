#ifndef FILEMANAGER_H
#define FILEMANAGER_H

#include <string>
#include <vector>

bool readFileLines(const std::string &path, std::vector<std::string> &lines)
{
    std::ifstream in(path);
    if (!in.is_open())
        return false;
    std::string line;
    while (std::getline(in, line))
        lines.push_back(line);
    in.close();
    return true;
    bool writeFileLines(const std::string &path, const std::vector<std::string> &lines);
}

#endif