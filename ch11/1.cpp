#include <iostream>

using namespace std;


struct X {
    int i;
    X(int);
    X operator+(int);
    X &operator=(const X &);
};

X::X(int n)
{
    cout << "X constructor with int\n";
    i = n;
}

X X::operator+(int n)
{
    cout << "Add x and int\n";
    X r = this->i + n;
    return r;
}

X &X::operator=(const X &x)
{
    cout << "X assign from " << (void *)&x << "to " << (void *)this << endl;
    this->i = x.i;
    return *this;
}

struct Y {
    int i;
    Y(X);
    Y operator+(X);
    operator int() const;
};

Y::Y(X x)
{
    cout << "Y construct with X\n";
    i = x.i;
}

Y Y::operator+(X x)
{
    cout << "Add y and x\n";
    X r = x + i;
    return r;
}

Y::operator int() const
{
    cout << "Y::int()\n";
    return i;
}

X operator*(X x, Y y)
{
    cout << "Multi x and y\n";
    return x.i*y.i;
}

int f(X x)
{
    return x.i + 10;
}

X x = 1;
Y y = x;
int i = 2;

int main()
{
    X x = 1; // constructor with i
    X xx = x + 2; // construct with i

    x = 4; // temporary object is create with 4 and operator= is called
    x = X(4);

    cout << "x:" << (void *)&x << endl;
    cout << "xx:" << (void *)&xx << endl;
    cout << xx.i << endl;


    cout << i + 10 << endl; // no type converting
    cout << y + X(10) << endl; // y+10 does not work, y+X(1) is converted into integer by Y::operator int()


    cout << y << endl; // int(y)

    // X(10)*y -> X by X operator*(X,Y)
    // Y + X -> Y by Y Y::operator+(X)
    // cout << Y -> cout << int(Y)
    cout << y + X(10)*y << endl;

    // y is converted into int by Y::int()
    // Add x and int
    // x+y is converted into X by X constructor with int
    // Add x and int i
    // final value is X by X constructor with int
    cout << (x+y+i).i << endl;

    // second x is converted into Y by Y construct with X
    // Multi x and y
    // x*x become temporary X by X constructor with int
    // Add x and int
    // final value is X by X constructor with int
    cout << (x*x+i).i << endl;

    // 7 is converted into X by X constructor with int
    cout << f(7) << endl;

    //f(y); y cannot be converted into X
    f(int(y)); // convert y into int and int is converted into X

    // both of y are converted into int
    cout << y+y << endl;

    // y is converted into int
    cout << 106 + y << endl;
    
}
