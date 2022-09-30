#include <iostream>
#include "HelloWorld.h"
#include "MathVector.h"
#include "length.h"

// using namespace std;

int main()
{
    std::cout << print() << '\n';
    double arr1[2] = {1, 2};
    double arr2[3] = {3, 4, 5};
    MathVector v1(2, arr1);
    MathVector v2(3, arr2);
    // try, catch
    double result = dot(v1, v2);
    return 0;
}