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
#pragma once

#include "dllutil.h"
#include "key.h"
#include <map>
#include <string>
#include <utility>
#include <vector>

namespace ini
{
    using SectionList = std::map<std::string, KeyList *>;

    class EXPORT_INI Section
    {
        SectionList groups;
        std::string current;

      public:
        Section();
        ~Section();

        void add_section(const std::string &name);
        void remove(const std::string &name);
        SectionList list() const;
        KeyList *get_key_list(const std::string &group);
        KeyList *get_current_keys();
        void add(const std::string &group, const std::string &name, const std::string &data);
        void add(const std::string &name, const std::string &data);
        bool remove(const std::string &group, const std::string &name);
        std::string get(const std::string &group, const std::string &name);
        std::string get(const std::string &name);
        void clear();

        std::string get_current_section();
        void set_current_section(const std::string &section_name);
    };
}
