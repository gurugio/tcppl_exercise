#include <iostream>

using namespace std;

struct call_error {
    int call_depth;
    call_error(int i) { call_depth = i; }
};


int return_value(int depth)
{
    return depth;
}

void throw_value(int depth)
{
    throw call_error(depth);
}


int main(int argc, char* argv[])
{
    clock_t start, end;
    int ret;

    start = clock();

    for (int i = 0; i < 0xffffff; i++)
    {
        ret = return_value(0xa3a3);
    }

    end = clock();

    cout << "Process took " << end - start << '\n';

    start = clock();

    for (int i = 0; i < 0xffffff; i++)
    {
        try
        {
            throw_value(0xa3a3);
        }
        catch (call_error e)
        {
            ret = e.call_depth;
        }
    }

    end = clock();

    cout << "Process took " << end - start << '\n';
}

//result
//Process took 59
//Process took 7908
