#include <gtest/gtest.h>
#include "../src/HelloWorld.h"
TEST(HELLOWORLD, Print)
{
    std::string compare = "Hello World";
    std::string output = print();
    ASSERT_EQ(compare, output);
}