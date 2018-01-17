#include "memoryfile.h"

namespace ini {
	MemoryFile::MemoryFile() : Groups()
	{
	}

	MemoryFile::~MemoryFile()
	{
	}

	void MemoryFile::open(string ini)
	{
		char ctoken;
		unsigned int current = 0;
		//criação temporária do nome do grupo.
		string grouptemp;
		const char *ckey;
		const char *cgroup = NULL;	
		//criação temporária do nome da chave.
		string keytemp;
		while(current <= ini.size()) {
			ctoken = ini[current];
			current++;
			switch(ctoken) {
				//grupo
				case '[':
					//comece com a string vazia.
					grouptemp = "";
					while(current < ini.size()) {
						ctoken = ini[current];
						current++;
						if (ctoken == ']' || ctoken == '\n') {
							//if (ctoken == '\n')
							//	cout << "Group error in line: " << line << endl;
							break;
						}
						//para erros e outras coisas mais.
						switch(ctoken) {
							case '[':
								//cout << "Group error in line: " << line << endl;
								break;
							default:
								grouptemp = grouptemp + ctoken;
						}
					}
					cgroup = grouptemp.c_str();
					addGroup(cgroup);
					break;
				//chave
				default:
					switch (ctoken) {
				case ' ':
					break;
				case '\n':
					break;
				default:
					keytemp = "";
					while(current <= ini.size()) {
						//se for igual a '=' saia do loop.
						if (ctoken == '=') {
							break;
						}
						//se não for espaço manda ver.
						if (ctoken != ' ') {
							keytemp = keytemp + ctoken;
						}
						ctoken = ini[current];
						current++;
					}
					//se não possuir o '=' na linha pule ela.
					if (ctoken == '\n') {
						break;
					}
					ckey = keytemp.c_str();
					//mandado para o while seguite.
					//filein.get(ctoken);
					while(current <= ini.size()) {
						ctoken = ini[current];
						current++;
						//se não possuir um caractere depois do '=' saia do loop;
						if (ctoken == '\n' || ctoken != ' ') {
							break;
						}
					}
					string keytemp2;
					while(current <= ini.size()) {
						//se for uma nova linha saia do loop.
						if (ctoken == '\n') {
							break;
						}
						keytemp2 = keytemp2 + ctoken;
						ctoken = ini[current];
						current++;
					}
					addKey(cgroup, ckey, keytemp2);
				}
			}
		}
	}

	string MemoryFile::save()
	{
		string file;
		map<string, Keys *> g = getGroups();
		register map<string, Keys *>::iterator i;
		map<string, string> key;
		register map<string, string>::iterator ikey;

		for (i = g.begin(); i != g.end(); i++) {
			file += "[" + (*i).first + "]\n";
			key = (*i).second->getKeys();
			for (ikey = key.begin(); ikey != key.end(); ikey++) {
				file += (*ikey).first + "=" + (*ikey).second + "\n";
			}
		}
		return file;
	}
}
