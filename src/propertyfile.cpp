#include "propertyfile.h"
#include <fstream>

using namespace ini;
using namespace std;

PropertyFile::PropertyFile() : KeyList{}
{
}

PropertyFile::~PropertyFile()
{
}

bool PropertyFile::open(string filename)
{
	clear();

	ifstream filein(filename, ios::in);
	if (!filein.is_open())
	{
		return false;
	}

	char ctoken;
	int line = 1;

	const char *ckey;

	// Temporary group.
	string keytemp;
	while (!filein.eof())
	{
		filein.get(ctoken);
		switch (ctoken)
		{
		case ' ':
			break;
		case '\n':
			line++;
			break;
		default:
			keytemp = "";
			while (!filein.eof())
			{
				//se for igual a '=' saia do loop.
				if (ctoken == '=')
				{
					break;
				}
				//se não for espaço manda ver.
				if (ctoken != ' ')
				{
					keytemp = keytemp + ctoken;
				}
				filein.get(ctoken);
			}
			//se não possuir o '=' na linha pule ela.
			if (ctoken == '\n')
			{
				break;
			}
			ckey = keytemp.c_str();

			while (!filein.eof())
			{
				filein.get(ctoken);
				//se não possuir um caractere depois do '=' saia do loop.
				if (ctoken == '\n' || ctoken != ' ')
				{
					break;
				}
			}
			string keytemp2;
			while (!filein.eof())
			{
				//se for uma nova linha saia do loop.
				if (ctoken == '\n')
				{
					break;
				}
				keytemp2 = keytemp2 + ctoken;
				filein.get(ctoken);
			}
			push_back({ ckey, keytemp2 });
		}
	}
	return true;
}

void PropertyFile::save(string filename)
{
	fstream file(filename.c_str(), ios::out);

	for (const auto &key : *this)
	{
		file << key.first << "=" << key.second << endl;
	}
	file.close();
}
