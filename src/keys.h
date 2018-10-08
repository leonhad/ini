#ifndef keys_h
#define keys_h

#include "dllutil.h"
#include <string>
#include <map>

namespace ini
{
	class EXPORT_INI Keys
	{
	public:
		~Keys();
		void addKey(std::string name, std::string data);
		std::string getKey(std::string name);
		void delKey(std::string name);
		std::map<std::string, std::string> getKeys();
		void clear();

	protected:
		std::map<std::string, std::string> dataList;
	};
}

#endif
