#ifndef _fileinterface_h
#define _fileinterface_h

#include <string>
#include "dllutil.h"

namespace ini
{
	class EXPORT_INI FileInterface
	{
	public:
		FileInterface();
		virtual ~FileInterface() = default;
		virtual bool open(std::string filename) = 0;
		virtual void save(std::string filename) = 0;
	};
}

#endif
