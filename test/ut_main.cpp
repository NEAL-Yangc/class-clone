#include <gtest/gtest.h>
#include "ut_length.h"
#include "ut_helloworld.h"
#include "ut_mathvector.h"
#include "ut_triangle.h"
#include "ut_polygon.h"

int main(int argc, char **argv)
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}