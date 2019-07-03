#include "pch.h"
#include "../src/key.h"
#include <string>

using namespace ini;
using namespace std;

string valueTest()
{
    Key keys({ "name", "value" });
    return keys.second;
}

TEST(KeyCase, Add)
{
    EXPECT_EQ("value", valueTest());
}
