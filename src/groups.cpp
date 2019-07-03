/*
 * This file is part of INI.
 * Copyright (C) 2012 Leonardo Alves da Costa
 * mailto:leonhad AT gmail DOT com
 *
 * PDF Tools is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 3 of the License, or (at your option) any later version.
 *
 * PDF Tools is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public License
 * along with this program; if not, write to the Free Software Foundation,
 * Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301, USA.
 */
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
