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
#include "Section.h"
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

void Section::SetCurrentSection(const std::string &section_name)
{
    this->current = section_name;
}

void Section::clear()
{
    for (const auto &group : m_groups)
    {
        delete group.second;
    }
    m_groups.clear();
}

void Section::remove(const string &name)
{
    delete m_groups[name];
    m_groups.erase(name);
    current = nullptr;
}

void Section::AddSection(const string &name)
{
    m_groups[name] = new KeyList{};
    current = name;
}

SectionList Section::list()
{
    return m_groups;
}

KeyList *Section::getKeyList(const string &group_name)
{
    current = group_name;

    for (const auto &group : m_groups)
    {
        if (group.first == group_name)
        {
            return group.second;
        }
    }
    return nullptr;
}

KeyList *Section::getCurrentKeys()
{
    return getKeyList(current);
}

void Section::add(const string &group, const string &name, const string &data)
{
    current = group;

    KeyList *keys = getKeyList(group);
    if (keys)
    {
        keys->emplace_back(name, data);
    }
}

void Section::add(const string &name, const string &data)
{
    add(current, name, data);
}

bool Section::remove(const string &group, const string &name)
{
    current = group;

    KeyList *keys = getKeyList(group);
    if (keys)
    {
        for (auto i = keys->begin(); i != keys->end(); ++i)
        {
            if (i->first == name)
            {
                keys->erase(i);
                return true;
            }
        }
    }

    return false;
}

string Section::get(const string &group, const string &name)
{
    current = group;

    const KeyList *keys = getKeyList(group);
    if (keys)
    {
        for (const auto &key : *keys)
        {
            if (key.first == name)
            {
                return key.second;
            }
        }
    }
    return "";
}

string Section::get(const string &name)
{
    return get(current, name);
}
