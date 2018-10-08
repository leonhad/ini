#include "inifile.h"

using namespace std;
using namespace ini;

IniFile::IniFile() : Groups()
{
}

IniFile::~IniFile()
{
}

bool IniFile::load()
{
    clear();

    ifstream filein(filename, ios::in);
    if (!filein.is_open())
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
    while (!filein.eof())
    {
        filein.get(ctoken);
        switch (ctoken)
        {
        //grupo
        case '[':
            //comece com a string vazia.
            grouptemp = "";
            while (!filein.eof())
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
                    //cout << "Group error in line: " << line << endl;
                    break;
                default:
                    grouptemp = grouptemp + ctoken;
                }
            }
            cgroup = grouptemp.c_str();
            addGroup(cgroup);
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
                while (!filein.eof())
                {
                    //se for igual a '=' saia do loop.
                    if (ctoken == '=')
                    {
                        break;
                    }
                    //se n�o for espa�o manda ver.
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

                while (!filein.eof())
                {
                    filein.get(ctoken);
                    //se não possuir um caractere depois do '=' saia do loop;
                    if (ctoken == '\n' || ctoken != ' ')
                    {
                        break;
                    }
                }
                string keytemp2;
                while (!filein.eof())
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
                addKey(cgroup, ckey, keytemp2);
            }
        }
    }
    return true;
}

void IniFile::save(string filename)
{
    file = new fstream(filename, ios::out);

    map<string, Keys *> g = getGroups();
    for (auto i = g.begin(); i != g.end(); i++)
    {
        *file << "[" << (*i).first << "]" << endl;
        auto key = (*i).second->getKeys();
        for (auto ikey = key.begin(); ikey != key.end(); ikey++)
        {
            *file << (*ikey).first << "=" << (*ikey).second << endl;
        }
    }

    close();
}
