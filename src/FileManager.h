#ifndef FILEMANAGER_H
#define FILEMANAGER_H

#include <string>
#include <vector>

bool readFileLines(const std::string &path, std::vector<std::string> &lines);
bool writeFileLines(const std::string &path, const std::vector<std::string> &lines);

#endif