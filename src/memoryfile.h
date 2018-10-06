#ifndef _memmoryfile_h
#define _memmoryfile_h

#include "fileinterface.h"
#include "groups.h"
#include <string>

using namespace std;

namespace ini
{
class MemoryFile : public Groups
{
  public:
    string comment;

    MemoryFile();
    virtual ~MemoryFile();
    void open(string ini);
    string save();
};
} // namespace ini

#endif
