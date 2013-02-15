#include <iostream>

using namespace std;

class Vector {
private:
    float *vectors;
    int vector_size;

public:
    Vector(int i);
    
    class Bad_range {};

    void check(int i) const { if (i < 0 || i >= vector_size) throw Bad_range(); }
    
    float operator[](int i) const { check(i); return vectors[i]; }

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

    cout << v << endl;
    
    v += 3;
    cout << v << endl;

    cout << v+4 << endl;


}
