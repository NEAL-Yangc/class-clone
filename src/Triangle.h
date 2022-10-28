#ifndef TRIANGLE_H
#define TRIANGLE_H

#include "MathVector.h"

class Triangle
{
private:
    MathVector _x, _y, _z;

public:
    Triangle() = default;
    Triangle(MathVector x, MathVector y, MathVector z) : _x(x), _y(y), _z(z){}; // same as _x = x
    Triangle(const Triangle &input) = delete;                                   // avoid using copy constructor
    ~Triangle();                                                                // destructor shuold not delete
    double area(void);
    double perimeter(void);
};

#endif
