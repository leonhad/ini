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
#include "memory.h"

using namespace ini;
using namespace std;

Memory::Memory() : Section()
{
}

Memory::~Memory()
{
}

Memory::Memory(string ini)
{
	unsigned int current = 0;

	// Current section name.
	string section = GetCurrentSection();

	while (current <= ini.size())
	{
		const char ctoken = ini[current];

		switch (ctoken)
		{
		case '[':
			ParseSection(ini, current);
			break;

		case ';':
		case '#':
			ParseComment(ini, current);
			break;

		case ' ':
		case '\n':
			// Ignore spaces and new lines
			current++;
			break;

		default:
			ParseKey(ini, section, current);
		}
	}
}

string Memory::Save()
{
	string file;

	for (auto group : list())
	{
		file += "[" + group.first + "]\n";
		for (const auto& key : *group.second)
		{
			file += key.first + "=" + key.second + "\n";
		}
	}
	return file;
}

void Memory::ParseKey(string ini, string cgroup, unsigned int& current)
{
	// Temporary key name.
	string ckey = "";
	do
	{
		// If token is a '=', break loop.
		if (ini[current] == '=')
		{
			break;
		}

		// Add token if is not an whitespace.
		if (ini[current] != ' ')
		{
			ckey += ini[current];
		}

		current++;
	} while (current <= ini.size());

	// If there is not a '=', skip that line.
	if (ini[current] == '\n')
	{
		return;
	}

	// Skip '=' char
	current++;

	// skip spaces
	while (current <= ini.size())
	{
		const char ctoken = ini[current];
		if (ctoken == '\n' || ctoken != ' ')
		{
			break;
		}

		current++;
	}

	string keytemp2;
	while (current <= ini.size())
	{
		//se for uma nova linha saia do loop.
		if (ini[current] == '\n')
		{
			break;
		}
		keytemp2 += ini[current];
		current++;
	}

	add(ckey, keytemp2);
}

void Memory::ParseSection(string ini, unsigned int& current)
{
	// Skip '[' char
	current++;

	string section = "";
	while (current < ini.size())
	{
		const char ctoken = ini[current];
		current++;
		if (ctoken == ']' || ctoken == '\n')
		{
			break;
		}

		section += ctoken;
	}

	AddSection(section);
}

void Memory::ParseComment(string ini, unsigned int& current)
{
	// Skip ';' or '#' char
	current++;

	string section = "";
	while (current < ini.size())
	{
		if (ini[current] == '\n')
		{
			break;
		}

		current++;
	}
}
