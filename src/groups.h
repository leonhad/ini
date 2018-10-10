#ifndef _groups_h
#define _groups_h

#include "dllutil.h"
#include "key.h"
#include <string>
#include <vector>
#include <map>
#include <utility>

namespace ini
{
	using GroupList = std::map<std::string, KeyList *>;

	class EXPORT_INI Groups
	{
	private:
		GroupList m_groups;
		std::string current;

	public:
		Groups();
		~Groups();
		void add(std::string name);
		void remove(std::string name);
		GroupList list();
		KeyList *getKeyList(std::string group);
		KeyList *getCurrentKeys();
		void add(std::string group, std::string name, std::string data);
		void add(std::string name, std::string data);
		bool remove(std::string group, std::string name);
		std::string get(std::string group, std::string name);
		std::string get(std::string name);
		void clear();
	};
}

#endif
