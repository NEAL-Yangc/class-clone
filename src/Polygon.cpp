#include "Polygon.h"

Polygon::Polygon()
{
    _arr = nullptr;
    _num = 0;
}

Polygon::~Polygon()
{
    if (_arr != nullptr)
    {
        delete[] _arr;
    }
}

Polygon::Polygon(MathVector *arr, int num)
{
    _arr = new MathVector[num];
    _num = num;
    for (int i = 0; i < num; i++)
    {
        _arr[i] = arr[i];
    }
}

double Polygon::area(void)
{
    return 0;
}

double Polygon::perimeter(void)
{
    double total = 0;
    for (int i = 0; i < _num - 1; i++)
    {
        total += (_arr[i] - _arr[i + 1]).length();
    }
    total += (_arr[_num - 1] - _arr[0]).length();
    return total;
}