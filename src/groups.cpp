#include "groups.h"
#include <map>

using namespace std;
using namespace ini;

void Groups::delGroup(string name)
{
    Keys *key = getKeys(name);
    delete key;
    groupList.erase(name);
    current.erase();
}

void Groups::addGroup(string name)
{
    groupList[name] = new Keys();
    current = name;
}

map<string, Keys *> Groups::getGroups()
{
    return groupList;
}

Keys *Groups::getKeys(string group)
{
    current = group;
    Keys *ret = nullptr;

    map<string, Keys *>::iterator i;
    for (i = groupList.begin(); i != groupList.end(); i++)
    {
        if ((*i).first == group)
        {
            ret = (*i).second;
            break;
        }
    }
    return ret;
}

Keys *Groups::getKeys()
{
    return getKeys(current);
}

void Groups::addKey(string group, string name, string data)
{
    current = group;
    Keys *keys = getKeys(group);
    if (keys)
    {
        keys->addKey(name, data);
    }
}

void Groups::addKey(string name, string data)
{
    addKey(current, name, data);
}

void Groups::delKey(string group, string name)
{
    current = group;
    Keys *keys = getKeys(group);
    if (keys)
    {
        keys->delKey(name);
    }
}

void Groups::delKey(string name)
{
    delKey(current, name);
}

string Groups::getKey(string group, string name)
{
    current = group;
    Keys *keys = getKeys(group);
    if (keys)
    {
        return keys->getKey(name);
    }
    return "";
}

string Groups::getKey(string name)
{
    return getKey(current, name);
}

void Groups::clear()
{
    map<string, Keys *>::iterator i;

    for (i = groupList.begin(); i != groupList.end(); i++)
    {
        delete (*i).second;
    }
    groupList.clear();
}

Groups::~Groups()
{
    clear();
}
