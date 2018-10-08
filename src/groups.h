#ifndef _groups_h
#define _groups_h

#include "keys.h"
#include "dllutil.h"
#include <string>
#include <vector>
#include <map>

namespace ini
{
	class EXPORT_INI Groups
	{
	private:
		std::map<std::string, Keys *> groupList;
		std::string current;

	public:
		~Groups();
		void addGroup(std::string name);
		void delGroup(std::string name);
		std::map<std::string, Keys *> getGroups();
		Keys *getKeys(std::string group);
		Keys *getKeys();
		void addKey(std::string group, std::string name, std::string data);
		void addKey(std::string name, std::string data);
		void delKey(std::string group, std::string name);
		void delKey(std::string name);
		std::string getKey(std::string group, std::string name);
		std::string getKey(std::string name);
		void clear();
	};
}

#endif
