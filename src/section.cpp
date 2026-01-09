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
    add_section("");
}

Section::~Section()
{
    clear();
}

string Section::get_current_section()
{
    return current;
}

void Section::set_current_section(const std::string &section_name)
{
    this->current = section_name;
}

void Section::clear()
{
    for (const auto &group : groups)
    {
        delete group.second;
    }

    groups.clear();
}

void Section::remove(const string &name)
{
    delete groups[name];
    groups.erase(name);
    current = nullptr;
}

void Section::add_section(const string &name)
{
    groups[name] = new KeyList{};
    current = name;
}

SectionList Section::list() const
{
    return groups;
}

KeyList *Section::get_key_list(const string &group_name)
{
    current = group_name;

    for (const auto &group : groups)
    {
        if (group.first == group_name)
        {
            return group.second;
        }
    }
    return nullptr;
}

KeyList *Section::get_current_keys()
{
    return get_key_list(current);
}

void Section::add(const string &group, const string &name, const string &data)
{
    current = group;

    KeyList *keys = get_key_list(group);
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

    KeyList *keys = get_key_list(group);
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

    const KeyList *keys = get_key_list(group);
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
