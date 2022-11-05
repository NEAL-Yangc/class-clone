#ifndef TRIANGLE_H
#define TRIANGLE_H

#include "MathVector.h"

class Triangle
{
private:
    MathVector _x, _y, _z;

public:
    Triangle() = default;
    Triangle(const MathVector &x, const MathVector &y, const MathVector &z) : _x(x), _y(y), _z(z)
    {
        std::cout << "lvalue &" << std::endl;
    };
    Triangle(MathVector &&x, MathVector &&y, MathVector &&z) : _x(std::move(x)), _y(std::move(y)), _z(std::move(z))
    {
        std::cout << "rvalue &&" << std::endl;
    };

    Triangle(const Triangle &input) = delete; // avoid using copy constructor
    ~Triangle();                              // destructor shuold not delete
    double area(void);
    double perimeter(void);
};

#endif
