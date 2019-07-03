#include "groups.h"
#include <map>

using namespace std;
using namespace ini;

Groups::Groups()
{
    current = nullptr;
}

Groups::~Groups()
{
    clear();
}

void Groups::clear()
{
    for (const auto &group : m_groups)
    {
        delete group.second;
    }
    m_groups.clear();
}

void Groups::remove(string name)
{
    delete m_groups[name];
    m_groups.erase(name);
    current = nullptr;
}

void Groups::add(string name)
{
    m_groups[name] = new KeyList{};
    current = name;
}

GroupList Groups::list()
{
    return m_groups;
}

KeyList *Groups::getKeyList(string name)
{
    current = name;
    
    for (const auto& group : m_groups)
    {
        if (group.first == name)
        {
            return group.second;
        }
    }
    return nullptr;
}

KeyList *Groups::getCurrentKeys()
{
    return getKeyList(current);
}

void Groups::add(string group, string name, string data)
{
    current = group;
    
    KeyList *keys = getKeyList(group);
    if (keys)
    {
        keys->push_back({ name, data });
    }
}

void Groups::add(string name, string data)
{
    add(current, name, data);
}

bool Groups::remove(string group, string name)
{
    current = group;
    
    KeyList *keys = getKeyList(group);
    if (keys)
    {
        for (auto i = keys->begin(); i != keys->end(); i++)
        {
            if ((*i).first == name)
            {
                keys->erase(i);
                return true;
            }
        }
    }
    
    return false;
}

string Groups::get(string group, string name)
{
    current = group;
    
    KeyList *keys = getKeyList(group);
    if (keys)
    {
        for (const auto& key : *keys)
        {
            if (key.first == name)
            {
                return key.second;
            }
        }
    }
    return "";
}

string Groups::get(string name)
{
    return get(current, name);
}
