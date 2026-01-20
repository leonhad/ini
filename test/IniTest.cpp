#include "pch.h"
#include "CppUnitTest.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

#include "../src/ini.h"
#include <sstream>

using namespace std;

namespace ini
{
	TEST_CLASS(MemoryFileTest)
	{
	public:

		TEST_METHOD(Open)
		{
			stringstream ini;
			ini <<  "test = 123\n[group]\ntest=321" ;
			Ini mem;
			mem.load(ini);

			Assert::AreEqual("123", mem.get("", "test").c_str());
			Assert::AreEqual("321", mem.get("group", "test").c_str());
		}

		TEST_METHOD(Comment)
		{
			stringstream ini;
			ini << "a =1\n;Comment\nb=2";
			Ini mem;
			mem.load(ini);

			Assert::AreEqual("1", mem.get("", "a").c_str());
			Assert::AreEqual("2", mem.get("", "b").c_str());
		}
	};
}
