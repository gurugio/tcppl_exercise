#include <iostream>
#include <vector>


using namespace std;


class MyExc { };


int *gg;

class Data {
public:
    int *p;
    Data(int s) { p = new int[s]; gg = p; cout << (void *)p << endl; }
    ~Data() { cout << "dest-Data\n"; delete[] p; }
};



class Y {
public:
    Data *d;
    void init()
    {
        cout << "init\n";
        throw MyExc();
    }

    Y(int s) {
        d = new Data(s);
        init();
    }
    ~Y() {
        cout << "destY\n";
    }
};



class Z {
public:
    Data d;
    void init() {
        cout << "init\n";
        throw MyExc();
    }

    Z(int s) : d(s) { init(); }
    ~Z() { cout << "destZ\n"; }
};

class X {
public:
    Data d;
    void init() {
        cout << "initX\n";
    }

    X(int s) : d(s) { init(); }
    ~X() { cout << "destX\n"; }
};

void f(void)
{

    X xx(4096);

    throw MyExc();
}

int main(void)
{
    cout << "start\n";

    try
    {
        Y yy(4096);
    }
    catch(...)
    {
        cout << (void *)gg << endl;;
        // Data of Y is not destroyed
        // Data of Y is lost
    }

    // when constructor occurs exception
    try
    {
        Z zz(4096);
    }
    catch(...)
    {
        cout << (void *)gg << endl;;
        // Data of Z is destroyed
        // destructor of Z is not called
    }

    try
    {
        f();
    }
    catch(MyExc e)
    {
        // resource of f()/xx object is destroyed here
    }
    
    cout << "finish\n";
}
   
