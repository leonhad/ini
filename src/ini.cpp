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
#include "ini.h"

using namespace ini;
using namespace std;

void Ini::load(istream &in)
{
    // Current section name.
    string section = get_current_section();
    char ctoken;

    while (not in.eof())
    {
        in.get(ctoken);

        switch (ctoken)
        {
        case '[':
            parse_section(in);
            break;

        case ';':
        case '#':
            parse_comment(in);
            break;

        case ' ':
        case '\n':
            // Ignore spaces and new lines
            break;

        default:
            in.unget();
            parse_key(in);
        }
    }
}

string Ini::to_string() const
{
    string file;

    for (const auto &group : list())
    {
        file += "[" + group.first + "]\n";
        for (const auto &key : *group.second)
        {
            file += key.first + "=" + key.second + "\n";
        }
    }
    return file;
}

void Ini::save(std::ostream &out) const
{
    for (const auto &group : list())
    {
        out << "[" << group.first << "]\n";
        for (const auto &key : *group.second)
        {
            out << key.first << "=" << key.second << "\n";
        }
    }
}

void Ini::parse_key(istream &in)
{
    // Temporary key name.
    string ckey;

    char current;
    do
    {
        in.get(current);

        // If the token is a '=', break the loop.
        if (current == '=')
        {
            break;
        }

        // Add token if is not whitespace.
        if (current != ' ')
        {
            ckey += current;
        }
    } while (not in.eof());

    // If there is not a '=', skip that line.
    if (current == '\n')
    {
        return;
    }

    // Skip '=' char
    if (current == '=')
    {
        in.get(current);
    }

    // skip spaces
    while (not in.eof())
    {
        if (current == '\n' || current != ' ')
        {
            break;
        }

        in.get(current);
    }

    string result_key;
    while (not in.eof())
    {
        // se for uma nova linha saia do loop.
        if (current == '\n')
        {
            break;
        }
        result_key += current;

        in.get(current);
    }

    add(ckey, result_key);
}

void Ini::parse_section(istream &in)
{
    char current;
    string section_name;

    while (not in.eof())
    {
        in.get(current);

        if (current == ']' || current == '\n')
        {
            break;
        }

        section_name += current;
    }

    add_section(section_name);
}

void Ini::parse_comment(istream &in)
{
    char current;

    while (not in.eof())
    {
        in.get(current);

        if (current == '\n')
        {
            break;
        }

        current++;
    }
}
