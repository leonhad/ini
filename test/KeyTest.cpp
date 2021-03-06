#include "pch.h"
#include "CppUnitTest.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

#include "../src/key.h"
#include <string>

using namespace std;

namespace ini
{
	TEST_CLASS(KeyTest)
	{
	public:
		
		TEST_METHOD(Add)
		{
			Key keys({ "name", "value" });
			Assert::AreEqual("value", keys.second.c_str());
		}
	};
}
