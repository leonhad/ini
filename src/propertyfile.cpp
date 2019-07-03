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
#include "propertyfile.h"
#include <fstream>

using namespace ini;
using namespace std;

PropertyFile::PropertyFile() : KeyList{}
{
}

PropertyFile::~PropertyFile()
{
}

bool PropertyFile::open(string filename)
{
    clear();
    
    ifstream filein(filename, ios::in);
    if (not filein.is_open())
    {
        return false;
    }
    
    char ctoken;
    int line = 1;
    
    const char *ckey;
    
    // Temporary group.
    string keytemp;
    while (not filein.eof())
    {
        filein.get(ctoken);
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
                    //se não for espaço manda ver.
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
                    //se não possuir um caractere depois do '=' saia do loop.
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
                    keytemp2 = keytemp2 + ctoken;
                    filein.get(ctoken);
                }
                push_back({ ckey, keytemp2 });
        }
    }
    return true;
}

void PropertyFile::save(string filename)
{
    fstream file(filename.c_str(), ios::out);
    
    for (const auto &key : *this)
    {
        file << key.first << "=" << key.second << endl;
    }
    file.close();
}
