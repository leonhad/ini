#ifndef KEYS_H
#define KEYS_H

#include <string>
#include <map>

using namespace std;

namespace ini {
    class Keys {
    public:
        ~Keys();
        void addKey(string name, string data);
        string getKey(string name);
        void delKey(string name);
        map<string, string> getKeys();
		void clear();
        
    protected:
        map<string, string> dataList;
    };
}

#endif

