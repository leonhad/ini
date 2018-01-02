#include "keys.h"
#include <stdlib.h>

using namespace std;

namespace ini {
    Keys::~Keys() {
        dataList.clear();
    }
    
    void Keys::addKey(string name, string data) {
        dataList.insert(map<string, string>::value_type(name, data));
    }
    
    void Keys::delKey(string name) {
        dataList.erase(name);
    }
    
    string Keys::getKey(string name) {
        return (*dataList.find(name)).second;
    }
    
    map<string, string> Keys::getKeys() {
        return dataList;
    }

	void Keys::clear() {
        dataList.clear();
    }
}

