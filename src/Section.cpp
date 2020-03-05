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
#include "section.h"
#include <map>

using namespace std;
using namespace ini;

Section::Section()
{
    AddSection(GetDefaultSection());
}

string Section::GetDefaultSection()
{
    return "";
}

Section::~Section()
{
    clear();
}

string Section::GetCurrentSection()
{
    return current;
}

void Section::SetCurrentSection(std::string current)
{
    this->current = current;
}

void Section::clear()
{
    for (const auto &group : m_groups)
    {
        delete group.second;
    }
    m_groups.clear();
}

void Section::remove(string name)
{
    delete m_groups[name];
    m_groups.erase(name);
    current = nullptr;
}

void Section::AddSection(string name)
{
    m_groups[name] = new KeyList{};
    current = name;
}

SectionList Section::list()
{
    return m_groups;
}

KeyList * Section::getKeyList(string name)
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

KeyList * Section::getCurrentKeys()
{
    return getKeyList(current);
}

void Section::add(string group, string name, string data)
{
    current = group;
    
    KeyList *keys = getKeyList(group);
    if (keys)
    {
        keys->push_back({ name, data });
    }
}

void Section::add(string name, string data)
{
    add(current, name, data);
}

bool Section::remove(string group, string name)
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

string Section::get(string group, string name)
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

string Section::get(string name)
{
    return get(current, name);
}
