#include "pch.h"
#include "CppUnitTest.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

#include "../src/memoryfile.h"
#include <string>

using namespace std;

namespace ini
{
	TEST_CLASS(MemoryFileTest)
	{
	public:

		TEST_METHOD(Open)
		{
			string ini = "test = 123\n[group]\ntest=321";
			MemoryFile file{ ini };

			Assert::AreEqual("123", file.get(file.GetDefaultSection(), "test").c_str());
			Assert::AreEqual("321", file.get("group", "test").c_str());
		}

		TEST_METHOD(Comment)
		{
			string ini = "a =1\n;Comment\nb=2";
			MemoryFile file{ ini };

			Assert::AreEqual("1", file.get(file.GetDefaultSection(), "a").c_str());
			Assert::AreEqual("2", file.get(file.GetDefaultSection(), "b").c_str());
		}
	};
}
