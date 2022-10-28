#ifndef POLYGON_H
#define POLYGON_H
#include "MathVector.h"

class Polygon
{
private:
    MathVector *_arr; // 點點 不定長度的arr
    int _num;         // 算邊
public:
    Polygon();
    ~Polygon();
    Polygon(MathVector *arr, int num);
    double area(void);
    double perimeter(void);
};

#endif