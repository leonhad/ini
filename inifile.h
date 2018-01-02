#ifndef _inifile_h
#define _inifile_h

#include "fileinterface.h"
#include "groups.h"
#include <string>

using namespace std;

namespace ini {
    class IniFile : public Groups, public FileInterface {
    public:
        IniFile();
        virtual ~IniFile();
        virtual void save(string filename);

    protected:
        virtual bool load();
    };
}

#endif
