#ifndef _fileinterface_h
#define _fileinterface_h

#include <string>
#include <fstream>

namespace ini
{
class FileInterface
{
  public:
    FileInterface();
    virtual ~FileInterface();
    bool open(std::string filename);
    void save();
    virtual void save(std::string filename) = 0;
    void flush();
    void reload();
    void close();
    bool isOpen();

  protected:
    std::string filename;
    std::fstream *file;

    virtual bool load() = 0;
};
} // namespace ini

#endif
