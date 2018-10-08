#ifndef propertyfile_h
#define propertyfile_h

#include "fileinterface.h"
#include "keys.h"
#include "dllutil.h"

namespace ini
{
	class EXPORT_INI PropertyFile : public FileInterface, public Keys
	{
	public:
		PropertyFile();
		virtual ~PropertyFile();
		virtual bool open(std::string filename) override;
		virtual void save(std::string filename) override;
	};
}

#endif
