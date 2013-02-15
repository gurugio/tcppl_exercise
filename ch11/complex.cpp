#include <iostream>

using namespace std;


class complex {
    double re, im;

public:
    complex(double r = 0, double i = 0) : re(r), im(i) {}


    
    complex &operator+=(complex a) {
        re += a.re;
        im += a.im;
        return *this;
    }

    complex &operator+=(double a) {
        re += a;
        return *this;
    }

    
    double real() const { return re; }
    double img() const { return im; }

    
    void show(void) {
        cout << re << "+" << im << "i" << endl;
    }
        
};


complex operator+(complex a, complex b)
{
    complex r = a;
    return r += b;
}

complex operator+(complex a, double b)
{
    complex r = b;
    return r += b;
}

complex operator+(double a, complex b)
{
    complex r = b;
    return r += a;
}

complex operator-(complex a)
{

}

complex operator+(complex a)
{

}

bool operator==(complex a, complex b)
{

}

bool operator!=(complex a, complex b)
{

}

istream &operator>>(istream &, complex &);
ostream &operator<<(ostream &, complex &);
complex polar(double rho, double theta);
complex conj(complex);

double abs(complex);
double arg(complex);
double norm(complex);

double real(complex);
double imag(complex);

complex acos(complex);
complex asin(complex);
complex atan(complex);



int main(void)
{
    complex b = 3;
    complex c;

    complex a = c+b;

    
    b.show();
    c.show();
    a.show();


        
}
