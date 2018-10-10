#ifndef keys_h
#define keys_h

#include "dllutil.h"
#include <string>
#include <vector>

namespace ini
{
	using Key = std::pair<std::string, std::string>;
	using KeyList = std::vector<Key>;
}

#endif
