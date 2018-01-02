#include <stdlib.h>
#include "fileinterface.h"

namespace ini{
    FileInterface::FileInterface() {
        file = NULL;
    }
    
    FileInterface::~FileInterface() {
        close();
    }
    
    bool FileInterface::open(string name) {
        this->filename = name;
        return load();
    }
    
    void FileInterface::save() {
        save(filename);
    }
    
    void FileInterface::flush() {
        if (file != NULL && file->is_open()) {
            file->flush();
        }
    }
    
    void FileInterface::reload() {
        close();
        load();
    }
    
    bool FileInterface::isOpen() {
        register bool ret = false;
        if (file != NULL) {
            ret = file->is_open();
        }
        return ret;
    }
    
    void FileInterface::close() {
        if (file) {
            if (file->is_open()) {
                file->flush();
                file->close();
            }
            delete file;
            file = NULL;
        }
    }
}

