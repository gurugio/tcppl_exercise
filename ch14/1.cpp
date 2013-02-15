#include <iostream>


using namespace std;


//typedef void (*unexpected_handler)();
//unexpected_handler set_unexpected(unexpected_handler);


// unexpected_handler type must be only void (*)(void).
// Is template useful??
class STC {
    unexpected_handler old;
public:
    STC(unexpected_handler f) { old = set_unexpected(f); }
    ~STC() { set_unexpected(old); }

};

void myhandler(void)
{
    cerr << "my unexpected-handler\n";
}


void f(void) throw(int)
{
    throw 'x';
}

void g(void) throw(int)
{
    throw 0;
}

int main(void) throw(int)
{

    try
    {
        g();
    }
    catch(int)
    {
        cout << "int-exception\n";
    }
    

    STC stc(myhandler);
    try
    {
        f();
    }
    catch(int)
    {
        cout << "int-exception\n";
    }

}
