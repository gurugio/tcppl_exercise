#include <iostream>

using namespace std;

struct call_error {
    int call_depth;
    call_error(int i) { call_depth = i; }
};



int main(int argc, char* argv[])
{

    try {
        throw call_error(3);
    }
    catch (call_error e)
    {
        cout << e.call_depth << endl;
    }

}

