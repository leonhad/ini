#include "inifile.h"

using namespace std;

namespace ini {
	IniFile::IniFile() : Groups()
	{
	}

	IniFile::~IniFile()
	{
	}

	bool IniFile::load()
	{
		clear();

		filebuf filebuffer;
		if (filename.empty()) {
			//if no name return
			return false;
		}
		//if not open, return.
		if (filebuffer.open(filename.c_str(), ios::in) == NULL) {
			return false;
		}
		istream filein(&filebuffer);
		char ctoken;
		int line = 1;
		//criação temporária do nome do grupo.
		string grouptemp;
		const char *ckey;
		const char *cgroup = NULL;	
		//criação temporária do nome da chave.
		string keytemp;
		while(!filein.eof()) {
			filein.get(ctoken);
			switch(ctoken) {
				//grupo
				case '[':
					//comece com a string vazia.
					grouptemp = "";
					while(!filein.eof()) {
						filein.get(ctoken);
						if (ctoken == ']' || ctoken == '\n') {
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
					line++;
					break;
				default:
					keytemp = "";
					while(!filein.eof()) {
						//se for igual a '=' saia do loop.
						if (ctoken == '=') {
							break;
						}
						//se não for espaço manda ver.
						if (ctoken != ' ') {
							keytemp = keytemp + ctoken;
						}
						filein.get(ctoken);
					}
					//se não possuir o '=' na linha pule ela.
					if (ctoken == '\n') {
						break;
					}
					ckey = keytemp.c_str();
					//mandado para o while seguite.
					//filein.get(ctoken);
					while(!filein.eof()) {
						filein.get(ctoken);
						//se não possuir um caractere depois do '=' saia do loop;
						if (ctoken == '\n' || ctoken != ' ') {
							break;
						}
					}
					string keytemp2;
					while(!filein.eof()) {
						//se for uma nova linha saia do loop.
						if (ctoken == '\n')
							break;
						//se não for espaço manda ver. mandado para o while anterior
						//if (ctoken != ' ')
						keytemp2 = keytemp2 + ctoken;
						filein.get(ctoken);
					}
					addKey(cgroup, ckey, keytemp2);
				}
			}
		}
		return true;
	}

	void IniFile::save(string filename)
	{
		file = new fstream(filename.c_str(), ios::out);

		map<string, Keys *> g = getGroups();
		register map<string, Keys *>::iterator i;
		map<string, string> key;
		register map<string, string>::iterator ikey;

		for (i = g.begin(); i != g.end(); i++) {
			*file << "[" << (*i).first << "]" << endl;
			key = (*i).second->getKeys();
			for (ikey = key.begin(); ikey != key.end(); ikey++) {
				*file << (*ikey).first << "=" << (*ikey).second << endl;
			}
		}

		close();
	}
}
