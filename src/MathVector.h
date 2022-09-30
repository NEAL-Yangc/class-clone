#ifndef MATH_VECTOR
#define MATH_VECTOR

#include <cmath>

class MathVector
{
private:
    int _dim;
    double *_arr; // uncertain size array
public:
    // Constructor
    MathVector() // default constructor
    {
        _dim = 0;
        _arr = NULL;
    }
    MathVector(int dim, double *arr)
    {
        _dim = dim;
        _arr = new double[_dim]; // be aware of memory leak
                                 // can be check with valgrind
                                 // sudo apt install valgrind
        // data, text, stack, heap
        for (int i = 0; i < _dim; i++)
        {
            _arr[i] = arr[i];
        }
    }
    MathVector(const MathVector &input) // copy constuctor
    {
        this->_dim = input._dim;
        this->_arr = new double[_dim];
        for (int i = 0; i < _dim; i++)
        {
            this->_arr[i] = input._arr[i];
        }
    }
    ~MathVector() // destructor
    {
        delete[] _arr; // [] means _arr is "a pointer to array"
    }
    // getter
    int
    getDim()
    {
        return _dim;
    }
    double getIndex(int i)
    {
        return _arr[i];
    }
    double length()
    {
        double sum = 0;
        for (int i = 0; i < _dim; i++)
        {
            sum += pow(_arr[i], 2);
        }
        return sqrt(sum);
    }
    // double dot(MathVector v1){}
    void multiply(double a)
    {
        for (int i = 0; i < _dim; i++)
        {
            _arr[i] *= a;
        }
    }
};

#endif