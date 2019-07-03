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
#include "memoryfile.h"

using namespace ini;
using namespace std;

MemoryFile::MemoryFile() : Groups()
{
}

MemoryFile::~MemoryFile()
{
}

void MemoryFile::open(string ini)
{
    char ctoken;
    unsigned int current = 0;
    //criação temporária do nome do grupo.
    string grouptemp;
    const char *ckey;
    const char *cgroup = nullptr;
    //criação temporária do nome da chave.
    string keytemp;
    while (current <= ini.size())
    {
        ctoken = ini[current];
        current++;
        switch (ctoken)
        {
                //grupo
            case '[':
                //comece com a string vazia.
                grouptemp = "";
                while (current < ini.size())
                {
                    ctoken = ini[current];
                    current++;
                    if (ctoken == ']' || ctoken == '\n')
                    {
                        break;
                    }
                    //para erros e outras coisas mais.
                    switch (ctoken)
                    {
                        case '[':
                            break;
                        default:
                            grouptemp = grouptemp + ctoken;
                    }
                }
                cgroup = grouptemp.c_str();
                add(cgroup);
                break;
                //chave
            default:
                switch (ctoken)
            {
                case ' ':
                    break;
                case '\n':
                    break;
                default:
                    keytemp = "";
                    while (current <= ini.size())
                    {
                        //se for igual a '=' saia do loop.
                        if (ctoken == '=')
                        {
                            break;
                        }
                        //se não for espaço manda ver.
                        if (ctoken != ' ')
                        {
                            keytemp = keytemp + ctoken;
                        }
                        ctoken = ini[current];
                        current++;
                    }
                    //se não possuir o '=' na linha pule ela.
                    if (ctoken == '\n')
                    {
                        break;
                    }
                    ckey = keytemp.c_str();
                    
                    while (current <= ini.size())
                    {
                        ctoken = ini[current];
                        current++;
                        
                        if (ctoken == '\n' || ctoken != ' ')
                        {
                            break;
                        }
                    }
                    string keytemp2;
                    while (current <= ini.size())
                    {
                        //se for uma nova linha saia do loop.
                        if (ctoken == '\n')
                        {
                            break;
                        }
                        keytemp2 = keytemp2 + ctoken;
                        ctoken = ini[current];
                        current++;
                    }
                    add(cgroup, ckey, keytemp2);
            }
        }
    }
}

string MemoryFile::save()
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
