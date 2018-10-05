#ifndef _groups_h
#define _groups_h

#include "keys.h"
#include <string>
#include <vector>
#include <map>

using namespace std;

namespace ini {
class Groups {
private:
    map<string, Keys *> groupList;
    string current;

public:
    ~Groups();
    void addGroup(string name);
    void delGroup(string name);
    map<string, Keys *> getGroups();
    Keys *getKeys(string group);
    Keys *getKeys();
    void addKey(string group, string name, string data);
    void addKey(string name, string data);
    void delKey(string group, string name);
    void delKey(string name);
    string getKey(string group, string name);
    string getKey(string name);
    void clear();
};

}

#endif
