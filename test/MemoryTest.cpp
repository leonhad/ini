#include "pch.h"
#include "CppUnitTest.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

#include "../src/memory.h"
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
			Memory file{ ini };

			Assert::AreEqual("123", file.get(file.GetDefaultSection(), "test").c_str());
			Assert::AreEqual("321", file.get("group", "test").c_str());
		}

		TEST_METHOD(Comment)
		{
			stringstream ini;
			ini << "a =1\n;Comment\nb=2";
			Memory file{ ini };

			Assert::AreEqual("1", file.get(file.GetDefaultSection(), "a").c_str());
			Assert::AreEqual("2", file.get(file.GetDefaultSection(), "b").c_str());
		}
	};
}
