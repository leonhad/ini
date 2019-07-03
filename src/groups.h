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
#ifndef _groups_h
#define _groups_h

#include "dllutil.h"
#include "key.h"
#include <string>
#include <vector>
#include <map>
#include <utility>

namespace ini
{
    using GroupList = std::map<std::string, KeyList *>;
    
    class EXPORT_INI Groups
    {
    private:
        GroupList m_groups;
        std::string current;
        
    public:
        Groups();
        ~Groups();
        void add(std::string name);
        void remove(std::string name);
        GroupList list();
        KeyList *getKeyList(std::string group);
        KeyList *getCurrentKeys();
        void add(std::string group, std::string name, std::string data);
        void add(std::string name, std::string data);
        bool remove(std::string group, std::string name);
        std::string get(std::string group, std::string name);
        std::string get(std::string name);
        void clear();
    };
}

#endif
