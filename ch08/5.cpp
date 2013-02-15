#include <iostream>

using namespace std;

struct call_error {
    int call_depth;
    call_error(int i) { call_depth = i; }
};


void g(int);

void f(int depth)
{
    if (depth < 10)
        g(depth+1);
    else
        throw call_error(10);
        
}

void g(int depth)
{
    if (depth < 11)
        f(depth+1);
    else
        throw call_error(11);
}

int main(int argc, char* argv[])
{

    try {
        f(0);
    }
    catch (call_error e)
    {
        cerr << "call error:" << e.call_depth << endl;
    }

}

