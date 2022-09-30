#include <gtest/gtest.h>
#include "../src/MathVector.h"
#include "../src/length.h"

TEST(MATHVECTOR, Dot)
{
    double arr1[2] = {1, 2};
    double arr2[2] = {3, 4};
    MathVector v1(2, arr1);
    MathVector v2(2, arr2);
    double result = dot(v1, v2);
    ASSERT_NEAR(result, 11, 0.01);
}

TEST(MATHVECTOR, Multiply)
{
    double arr1[2] = {1, 2};
    MathVector v1(2, arr1);
    v1.multiply(3); //  return nothing
    ASSERT_NEAR(v1.getIndex(0), 3, 0.01);
    ASSERT_NEAR(v1.getIndex(1), 6, 0.01);
}

TEST(MATHVECTOR, DotThrow)
{
    double arr1[2] = {1, 2};
    double arr2[3] = {3, 4, 5};
    MathVector v1(2, arr1);
    MathVector v2(3, arr2);
    ASSERT_THROW(dot(v1, v2), std::string);
}