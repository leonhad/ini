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
#include "inifile.h"
#include <fstream>

using namespace std;
using namespace ini;

IniFile::IniFile() : Groups()
{
}

IniFile::~IniFile()
{
}

bool IniFile::open(string filename)
{
    clear();
    
    ifstream filein(filename, ios::in);
    if (not filein.is_open())
    {
        return false;
    }
    
    char ctoken;
    int line = 1;
    //criação temporária do nome do grupo.
    string grouptemp;
    const char *ckey;
    const char *cgroup = nullptr;
    //criação temporária do nome da chave.
    string keytemp;
    while (not filein.eof())
    {
        filein.get(ctoken);
        switch (ctoken)
        {
                //grupo
            case '[':
                //comece com a string vazia.
                grouptemp = "";
                while (not filein.eof())
                {
                    filein.get(ctoken);
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
                    line++;
                    break;
                default:
                    keytemp = "";
                    while (not filein.eof())
                    {
                        //se for igual a '=' saia do loop.
                        if (ctoken == '=')
                        {
                            break;
                        }
                        // continue if not space.
                        if (ctoken != ' ')
                        {
                            keytemp = keytemp + ctoken;
                        }
                        filein.get(ctoken);
                    }
                    //se não possuir o '=' na linha pule ela.
                    if (ctoken == '\n')
                    {
                        break;
                    }
                    ckey = keytemp.c_str();
                    
                    while (not filein.eof())
                    {
                        filein.get(ctoken);
                        
                        if (ctoken == '\n' || ctoken != ' ')
                        {
                            break;
                        }
                    }
                    string keytemp2;
                    while (not filein.eof())
                    {
                        //se for uma nova linha saia do loop.
                        if (ctoken == '\n')
                        {
                            break;
                        }
                        
                        //se não for espaço manda ver. mandado para o while anterior
                        keytemp2 = keytemp2 + ctoken;
                        filein.get(ctoken);
                    }
                    add(cgroup, ckey, keytemp2);
            }
        }
    }
    return true;
}

void IniFile::save(string filename)
{
    fstream file(filename, ios::out);
    
    auto g = list();
    for (auto group : g)
    {
        file << "[" << group.first << "]" << endl;
        for (auto key : *group.second)
        {
            file << key.first << "=" << key.second << endl;
        }
    }
    file.close();
}
