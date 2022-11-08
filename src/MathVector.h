#ifndef MATH_VECTOR
#define MATH_VECTOR

#include <cmath>
#include <iostream>

class MathVector
{
private:
    int _dim;
    double *_arr; // uncertain size array
public:
    // Constructor
    MathVector() : _dim(0), _arr(nullptr){}; // default constructor
    ~MathVector() { delete[] _arr; };        // destructor
    void init(int dim, double *arr);
    MathVector(int dim, double *arr) { init(dim, arr); };
    MathVector(const MathVector &input) : MathVector(input._dim, input._arr){}; // copy constructor
    MathVector(MathVector &&input);                                             // move construcor
    MathVector &operator=(const MathVector &input);                             // copy assignment, in other word is "=" overloading
    MathVector &operator=(MathVector &&input);
    MathVector operator+(const MathVector &input);
    MathVector operator-(const MathVector &input);
    MathVector operator/(const MathVector &input);
    bool operator>(const MathVector &input);
    bool operator<(const MathVector &input);
    std::string toString();
    // getter
    int getDim() const;
    double getIndex(int i) const;
    double length() const;
    // double dot(MathVector v1){}
    void multiply(double a);
};

#endif
