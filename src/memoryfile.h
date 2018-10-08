#ifndef _memmoryfile_h
#define _memmoryfile_h

#include "fileinterface.h"
#include "groups.h"
#include "dllutil.h"
#include <string>

using namespace std;

namespace ini
{
	class EXPORT_INI MemoryFile : public Groups
	{
	public:
		MemoryFile();
		virtual ~MemoryFile();
		void open(string ini);
		string save();
	};
}

#endif
