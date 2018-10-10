#pragma once

#include "dllutil.h"

namespace ini {
	class EXPORT_INI MapKey
	{
		char *key;
		char *value;
	};

	class EXPORT_INI Map
	{
	public:
		Map();
		~Map();
		void put(const char *key, const char *value);
		const char *get(const char *key);
		bool remove(const char *key);
		int size();

	private:
		int m_size;
	};
}
