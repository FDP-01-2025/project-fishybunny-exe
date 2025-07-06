#ifndef SKILLMANAGER_H
#define SKILLMANAGER_H

#include <string>
#include <vector>
using namespace std;

sstruct Skill {
    string name;
    int cost;
    int typeID;
    bool special;
};

void loadSkills();
const vector<Skill>& getAllSkills();
void showSkills();


#endif



