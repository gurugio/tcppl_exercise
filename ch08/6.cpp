#include <iostream>

using namespace std;

struct call_error {
    int call_depth;
    call_error(int i) { call_depth = i; }
};


void g(int, int);

void f(int depth, int max)
{
    if (depth < max)
        g(depth+1, max);
    else
        throw call_error(max);
        
}

void g(int depth, int max)
{
    if (depth < max+1)
        f(depth+1, max);
    else
        throw call_error(max+1);
}

void g_with_string(int depth, int max);

void f_with_string(int depth, int max)
{
     string dummy("abcd");
    if (depth < max)
        g_with_string(depth+1, max);
    else
        throw call_error(max);
        
}

void g_with_string(int depth, int max)
{
     string dummy("abcd");
    if (depth < max+1)
        f_with_string(depth+1, max);
    else
        throw call_error(max+1);
}

int main(int argc, char* argv[])
{
    clock_t start, end;

    start = clock();

    try {
        f(0, 10000);
    }
    catch (call_error e)
    {
        cerr << "call error:" << e.call_depth << endl;
    }

    end = clock();

    cout << "Process took " << end - start << '\n';

    start = clock();

    try {
        f_with_string(0, 10000);
    }
    catch (call_error e)
    {
        cerr << "call error:" << e.call_depth << endl;
    }

    end = clock();

    cout << "Process took " << end - start << '\n';

}

//result
//call error:10000
//Process took 1
//call error:10000
//Process took 9
