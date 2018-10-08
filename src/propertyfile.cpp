#include "propertyfile.h"

using namespace ini;

PropertyFile::PropertyFile() : Keys()
{
}

PropertyFile::~PropertyFile()
{
}

bool PropertyFile::load()
{
    clear();

    ifstream filein(filename, ios::in);
    if (!filein.is_open())
    {
        return false;
    }
 
    char ctoken;
    int line = 1;
    // Temporary group name.
    string grouptemp;
    const char *ckey;

    // Temporary group.
    string keytemp;
    while (!filein.eof())
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
            while (!filein.eof())
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
                keytemp2 = keytemp2 + ctoken;
                filein.get(ctoken);
            }
            addKey(ckey, keytemp2);
        }
    }
    return true;
}

void PropertyFile::save(string filename)
{
    file = new fstream(filename.c_str(), ios::out);
    auto key = getKeys();
    for (auto ikey = key.begin(); ikey != key.end(); ikey++)
    {
        *file << (*ikey).first << "=" << (*ikey).second << endl;
    }

    close();
}
