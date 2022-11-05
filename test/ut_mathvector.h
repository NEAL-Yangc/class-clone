#include <gtest/gtest.h>
#include "../src/MathVector.h"
#include "../src/length.h"
#include "../src/Triangle.h"

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
TEST(MATHVECTOR, Assgiment)
{
    double arr1[2] = {1, 2};
    double arr2[3] = {3, 4, 5};
    double arr3[3] = {6, 7, 8};
    MathVector v1(2, arr1);
    MathVector v2(3, arr2);
    MathVector v3(3, arr3);

    v1 = v2;
    ASSERT_EQ(v1.getDim(), 3);
    ASSERT_NEAR(v1.getIndex(0), arr2[0], 0.01);
    ASSERT_NEAR(v1.getIndex(1), arr2[1], 0.01);
    ASSERT_NEAR(v1.getIndex(2), arr2[2], 0.01);
    v1 = v2 = v3;
    ASSERT_EQ(v1.getDim(), 3);
    ASSERT_NEAR(v1.getIndex(0), arr3[0], 0.01);
    ASSERT_NEAR(v1.getIndex(1), arr3[1], 0.01);
    ASSERT_NEAR(v1.getIndex(2), arr3[2], 0.01);
    ASSERT_EQ(v2.getDim(), 3);
    ASSERT_NEAR(v2.getIndex(0), arr3[0], 0.01);
    ASSERT_NEAR(v2.getIndex(1), arr3[1], 0.01);
    ASSERT_NEAR(v2.getIndex(2), arr3[2], 0.01);
}

TEST(MATHVECTOR, Add)
{
    double arr2[3] = {3, 4, 5};
    double arr3[3] = {6, 7, 8};
    MathVector v1;
    MathVector v2(3, arr2);
    MathVector v3(3, arr3);

    v1 = v2 + v3;
    ASSERT_EQ(v1.getDim(), 3);
    ASSERT_NEAR(v1.getIndex(0), 9, 0.01);
    ASSERT_NEAR(v1.getIndex(1), 11, 0.01);
    ASSERT_NEAR(v1.getIndex(2), 13, 0.01);
}
TEST(MATHVECTOR, Compare)
{
    double arr2[3] = {3, 4, 5};
    double arr3[3] = {6, 7, 8};
    MathVector v2(3, arr2);
    MathVector v3(3, arr3);
    // if(v2.length() < v3.length()) {}
    ASSERT_FALSE(v2 > v3);
    ASSERT_TRUE(v2 < v3);
}
TEST(MATHVECTOR, ToString)
{
    double arr2[3] = {3, 4, 5};
    MathVector v2(3, arr2);
    int i = 0;
    std::cout << v2.toString() << std::endl;
    // std::cout << v2 << std::endl; // TBD
}
TEST(MATHVECTOR, Divide)
{
    double arr2[3] = {3, 4, 5};
    double arr3[3] = {6, 12, 20};
    MathVector v1;
    MathVector v2(3, arr2);
    MathVector v3(3, arr3);
    v1 = v3 / v2;
    ASSERT_NEAR(v1.getIndex(0), 2, 0.01);
    ASSERT_NEAR(v1.getIndex(1), 3, 0.01);
    ASSERT_NEAR(v1.getIndex(2), 4, 0.01);
}
