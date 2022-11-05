#include "MathVector.h"

// Constructor
// MathVector::MathVector() // default constructor
// {
//     _dim = 0;
//     _arr = NULL;
// }

// MathVector::~MathVector() // destructor
// {
//     delete[] _arr; // [] means _arr is "a pointer to array"
// }

void MathVector::init(int dim, double *arr)
{
    _dim = dim;

    // if (_arr != NULL)     // this is we want to check the memory is NEWed or not, if yes, we need to delete.
    // {                     // but you can see the flowing code, 38. 42. 61. 81. constructor didn't initialize.
    //     delete[] _arr;    // is means when constructor builded is not to initialize, _dim, *_arr will get some trash in memory.
    // }                     // So, this if will judge the _arr not a NULL and delete the _arr, but this is BUG!

    /*
            if we want this statment work, we need to initailize every constructor when we call it.
    */

    _arr = new double[_dim]; // be aware of memory leak
                             // can be check with valgrind
                             // sudo apt install valgrind
    // data, text, stack, heap
    for (int i = 0; i < _dim; i++)
    {
        _arr[i] = arr[i];
    }
}

// MathVector::MathVector(int dim, double *arr)
// {
//     init(dim, arr);
// }
// MathVector::MathVector(const MathVector &input)
/*
    應該在複製各種參數時，跟記憶體要新的空間拿來存放，而不是複製一樣得address，避免double free
    因為「複製進來跟外面的是指向同一個地址」，誰先delete[]就已經free到了

    [10/10 下午9:46] 楊士賢
    copy constructor 就是要避免在引入參數時，當她有ptr時，避免出現copy同一個地方<

    [10/10 下午9:46] 楊士賢
    造成我可能在free時free了已經被free的地方嗎?

    [10/10 下午9:47] 楊士賢
    避免出現double free的尷尬狀況

    copy constructor is when we build the another object
    copy constructor, make sure do not occured the chicken-and-egg conundrum. so we need to pass by reference
    const is make sure inside value doesn't change outside value
    & is pass by reference
*/
// {
//     //_dim = input.getDim();    // if want to use getDim() you need to make sure this function doesn't change the value
//     // this->_dim = input._dim; // this-> is point to private value. in other word is try to use the value.
//     //                          // input.dim work.because the input._dim and this->_dim is by the same class builded, so you know me and I know you.
//     // this->_arr = new double[_dim];
//     // for (int i = 0; i < _dim; i++)
//     // {
//     //     this->_arr[i] = input._arr[i];
//     // }
//     // this is a pointer, pointing to object itself

//     init(input._dim, input._arr);
//     std::cout << "copy constructor" << std::endl;
// }

// this & means we want to return by reference. if no add & is return by value is means copy.

MathVector::MathVector(MathVector &&input)
{
    this->_dim = input._dim;
    this->_arr = input._arr;

    input._dim = 0;
    input._arr = nullptr;
}

MathVector &MathVector::operator=(const MathVector &input)
{
    // if a = a; // we don't want to process this situation.

    // object-level comparing (*this != input)
    // this is a pointer. so *this is object, to compare *this object is equal input object or not.
    // but we don't use object-level comparing. because we haven't defined != is.
    // adress-level comparing

    if (this != &input) // if this point to address have same object as the input object, we don't process
    {
        if (this->_arr != nullptr) // if this itself _arr's value is not a NULL, we need to release the heap
        {
            delete[] this->_arr;
        }
        init(input._dim, input._arr);
    }
    // input._dim = 4; // doesn't work because we dont't want to change the value, so we marked const.
    return *this;
    //* is dereference operator. we want to return the object not a address.
}

MathVector &MathVector::operator=(const MathVector &&input)
{
    if (this != &input)
    {
        this->_dim = std::move(input._dim);
        this->_arr = std::move(input._arr);
    }
    return *this;
}

MathVector MathVector::operator+(const MathVector &input)
{
    double *tmp = new double[input.getDim()];
    for (int i = 0; i < input.getDim(); i++)
    {
        tmp[i] = this->_arr[i] + input._arr[i];
    }
    MathVector m = MathVector(input.getDim(), tmp);
    delete[] tmp;
    return m;
    // return MathVector(input.getDim(), tmp); // no copy costructor <- copy elision (加速)
    /*
    if only do this one tmp will still in heap, will occuped the leaks
    so we need to build the container to contain the object and DELETE!! the tmp
    */
}

MathVector MathVector::operator-(const MathVector &input)
{
    double *tmp = new double[input.getDim()];
    for (int i = 0; i < input.getDim(); i++)
    {
        tmp[i] = this->_arr[i] - input._arr[i];
    } // this one
    MathVector m = MathVector(input.getDim(), tmp);
    delete[] tmp;
    return m;
    // return MathVector(input.getDim(), tmp); // no copy costructor <- copy elision (加速)
    /*
    if only do this one tmp will still in heap, will occuped the leaks
    so we need to build the container to contain the object and DELETE!! the tmp
    */
}

MathVector MathVector::operator/(const MathVector &input)
{
    double *tmp = new double[input.getDim()];
    for (int i = 0; i < input.getDim(); i++)
    {
        tmp[i] = this->_arr[i] / input._arr[i];
    }
    MathVector m = MathVector(input.getDim(), tmp);
    delete[] tmp;
    return m;
}

bool MathVector::operator>(const MathVector &input)
{
    return this->length() > input.length();
}

bool MathVector::operator<(const MathVector &input)
{
    return this->length() < input.length();
}

std::string MathVector::toString()
{
    std::string tmp = "Dim : ";
    tmp += std::to_string(this->_dim);
    tmp += ", location is [";
    for (int i = 0; i < _dim; i++)
    {
        tmp += std::to_string(this->_arr[i]);
        if (i != this->_dim - 1)
        {
            tmp += ",";
        }
    }
    tmp += "]";
    return tmp;
}
// std::ostream operator<<()
// {

// }
// getter
int MathVector::getDim() const
{
    return _dim;
}

double MathVector::getIndex(int i) const
{
    return _arr[i];
}

double MathVector::length() const
{
    double sum = 0;
    for (int i = 0; i < _dim; i++)
    {
        sum += pow(_arr[i], 2);
    }
    return sqrt(sum);
}

// double dot(MathVector v1){}
void MathVector::multiply(double a)
{
    for (int i = 0; i < _dim; i++)
    {
        _arr[i] *= a;
    }
}
