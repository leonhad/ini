#include <stdlib.h>
#include "fileinterface.h"

using namespace ini;
using namespace std;

FileInterface::FileInterface()
{
    file = nullptr;
}

FileInterface::~FileInterface()
{
    close();
}

bool FileInterface::open(string name)
{
    this->filename = name;
    return load();
}

void FileInterface::save()
{
    save(filename);
}

void FileInterface::flush()
{
    if (file != nullptr && file->is_open())
    {
        file->flush();
    }
}

void FileInterface::reload()
{
    close();
    load();
}

bool FileInterface::isOpen()
{
    bool ret = false;
    if (file != nullptr)
    {
        ret = file->is_open();
    }
    return ret;
}

void FileInterface::close()
{
    if (file)
    {
        if (file->is_open())
        {
            file->flush();
            file->close();
        }
        delete file;
        file = nullptr;
    }
}
