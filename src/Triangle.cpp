#include "Triangle.h"
#include <cmath>

/*
Triangle::Triangle()
{
    _x = x;
    _y = y;
    _z = z;
}
*/
double Triangle::area(void)
{
    double a, b, c, s;

    a = (_x - _y).length();
    b = (_y - _z).length();
    c = (_z - _x).length();

    s = (a + b + c) / 2;
    //海龍公式
    return sqrt(s * (s - a) * (s - b) * (s - c));
}

double Triangle::perimeter(void)
{
    double tmp = 0;

    tmp = (_x - _y).length();
    tmp += (_y - _z).length();
    tmp += (_z - _x).length();

    return tmp;
}

Triangle::~Triangle()
{
}