#include <iostream>

using namespace std;

class Imaginary {
    double im;
public:
    Imaginary(double i = 0) : im(i) {}

    friend ostream &operator<<(ostream &os, Imaginary &img)
    {
        os << img.im;
        return os;
    }

    friend istream &operator>>(istream &os, Imaginary &img)
    {
        os >> img.im;
        return os;
    }

    Imaginary &operator+=(Imaginary a) {
        im += a.im;
        return *this;
    }

};

class complex {
    double re;
    Imaginary img;
    
public:
    complex(double r = 0, double i = 0) : re(r), img(i)
    {
        cout << "make complex with " << r << ":" << i << endl;
    }

    
    complex &operator+=(complex a) {
        re += a.re;
        img += a.img;
        return *this;
    }

    
    void show(void) {
        cout << re << "+" << img << "i" << endl;
    }

    friend istream &operator>>(istream &os, complex &com);
    friend ostream &operator<<(ostream &os, complex &com);

};


complex operator+(complex a, complex b)
{
    complex r = a;
    return r += b;
}


istream &operator>>(istream &os, complex &com)
{
    os >> com.re >> com.img;
    return os;
}

ostream &operator<<(ostream &os, complex &com)
{
    os << com.re << "+" << com.img << "i";
    return os;
}


int main(void)
{
    complex b = 3;
    complex c;

    b.show();
    
    c += b;
    c.show();

    c += 4;
    c.show();

    complex a = c+b;

    cout << a << endl;

    cout << "input numbers:";
    cin >> a;
    cout << a << endl;
}
