#ifndef _inifile_h
#define _inifile_h

#include "fileinterface.h"
#include "groups.h"
#include "dllutil.h"
#include <string>

namespace ini
{
	class EXPORT_INI IniFile : public Groups, public FileInterface
	{
	public:
		IniFile();
		virtual ~IniFile();
		virtual bool open(std::string filename) override;
		virtual void save(std::string filename) override;
	};
}

#endif
