#include <gtest/gtest.h>
#include "../src/length.h"
TEST(LENGTH_TEST, TwoDim)
{
    double arr[] = {3, 4};
    int dim = 2;
    double output = length(arr, dim);
    ASSERT_EQ(output, 5);
}

TEST(LENGTH_TEST, ThreeDim)
{
    double arr[] = {3, 4, 5};
    int dim = 3;
    double output = length(arr, dim);
    ASSERT_NEAR(output, 7.07, 0.01);
}

TEST(LENGTH_TEST, TwoDimMathVector)
{
    double arr[] = {3, 4};
    int dim = 2;
    // MathVector m; -> default constructor
    MathVector m(dim, arr);
    double output = length(m); // copy constructor
    ASSERT_EQ(output, 5);
}
// void fun(int i){
//     i = 10;
// }
// main()
//  int i = 0;
//  fun(i); -> copy
//  pass by value
