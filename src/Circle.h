#ifndef CIRCLE_H
#define CIRCLE_H
#include "MathVector.h"

class Circle
{
private:
    MathVector _center;
    double _redius;

public:
    Circle() = default;
    Circle(MathVector c, double r);
    ~Circle();
    double area(void);
    double perimeter(void);
};

#endif