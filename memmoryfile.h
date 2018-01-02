#ifndef _memmoryfile_h
#define _memmoryfile_h

#include "fileinterface.h"
#include "groups.h"
#include <string>

using namespace std;

namespace ini {
    class MemmoryFile : public Groups {
    public:
        string comment;

        MemmoryFile();
        virtual ~MemmoryFile();
		void open(string ini);
		string save();
    };
}


#endif

