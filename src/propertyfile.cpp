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

    filebuf filebuffer;
    if (filename.empty())
    {
        //if no name return
        return false;
    }
    //if not open, return.
    if (filebuffer.open(filename.c_str(), ios::in) == nullptr)
    {
        return false;
    }
    istream filein(&filebuffer);
    char ctoken;
    int line = 1;
    // Temporary group name.
    string grouptemp;
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
                //se n�o for espa�o manda ver.
                if (ctoken != ' ')
                {
                    keytemp = keytemp + ctoken;
                }
                filein.get(ctoken);
            }
            //se n�o possuir o '=' na linha pule ela.
            if (ctoken == '\n')
            {
                break;
            }
            ckey = keytemp.c_str();
            //mandado para o while seguite.
            //filein.get(ctoken);
            while (not filein.eof())
            {
                filein.get(ctoken);
                //se n�o possuir um caractere depois do '=' saia do loop;
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
                //se n�o for espa�o manda ver. mandado para o while anterior
                //if (ctoken != ' ')
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

    map<string, string> key;
    map<string, string>::iterator ikey;

    key = getKeys();
    for (ikey = key.begin(); ikey != key.end(); ikey++)
    {
        *file << (*ikey).first << "=" << (*ikey).second << endl;
    }

    close();
}
