#include <iostream>
#include <exception>
#include <stdexcept>

using namespace std;


class Size : public exception {
    string msg;
public:
    Size(const string &msg) { this->msg = msg; }

    // destructor must not throw any exception
    ~Size() throw() {} 
};

class Vector {
private:
    float *vectors;
    int vector_size;

public:
    Vector(int i);
    
    void check(int i) const { if (i < 0 || i >= vector_size) throw out_of_range("wrong index"); }
    
    float &operator[](int i) const { check(i); return vectors[i]; }

    Vector &operator+=(float val);

    friend ostream &operator<<(ostream &os, const Vector &vec);
    
};

Vector::Vector(int i) : vector_size(i)
{
    vectors = new float[i];
    for (int i = 0; i < vector_size; i++)
        vectors[i] = 0;
}

Vector &Vector::operator+=(float val)
{
    if (val > 10)
        throw Size("too big operand");
    
    for (int i = 0; i < vector_size; i++)
    {
        vectors[i] += val;
    }
    return *this;
}

Vector operator+(const Vector vec, float val)
{
    Vector temp = vec;
    temp += val;
    return temp;
}

ostream &operator<<(ostream &os, const Vector &vec)
{
    for (int i = 0; i < vec.vector_size; i++)
        os << vec.vectors[i] << ',';
    return os;
}


int main(void)
{
    Vector v(4);
    int sum;

    v[0] = v[1] = v[2] = v[3] = 3;

    try
    {
        sum = 0;
        for (int i = 0; ; i++)
        {
            sum += v[i];
        }
    }
    catch(exception &e)
    {
        // summation is not error!
        cout << "sum=" << sum << endl;
    }

}
