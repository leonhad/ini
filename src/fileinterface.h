#ifndef _fileinterface_h
#define _fileinterface_h

#include <string>
#include <fstream>

using namespace std;

namespace ini {
    class FileInterface {
    public:
        FileInterface();
        virtual ~FileInterface();
        bool open(string filename);
        void save();
        virtual void save(string filename) = 0;
        void flush();
        void reload();
        void close();
        bool isOpen();
        
    protected:
        string filename;
        fstream *file;

        virtual bool load() = 0;
    };    
}

#endif
