#include "Circle.h"

// Circle::Circle()
// {
// }

Circle::~Circle()
{
}

Circle::Circle(MathVector c, double r)
{
    _center = c;
    _redius = r;
}

double Circle::area(void)
{
    return _redius * _redius * M_PI;
}

double Circle::perimeter(void)
{
    return 2 * _redius * M_PI;
}