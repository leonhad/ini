#ifndef propertyfile_h
#define propertyfile_h

#include "fileinterface.h"
#include "keys.h"

namespace ini {
class PropertyFile : public FileInterface, public Keys {
public:
    PropertyFile();
    virtual ~PropertyFile();
    virtual void save(string filename);

protected:
    virtual bool load();
};
}

#endif
