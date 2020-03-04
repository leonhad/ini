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
#ifndef _memmoryfile_h
#define _memmoryfile_h

#include "section.h"
#include "dllutil.h"
#include <string>
#include <iostream>

namespace ini
{
	class EXPORT_INI Memory : public Section
	{
	public:
		Memory();
        Memory(std::istream &in);

		virtual ~Memory();
		std::string ToString();

	private:
		void ParseSection(std::istream &in);
		void ParseKey(std::istream &in, std::string &cgroup);
		void ParseComment(std::istream &in);
	};
}

#endif