#include<iostream>

using namespace std;


int main(int argc, char *argv[])
{
    for (--argc; argc > 0; argc--)
    {
        cout << "hello, " << argv[argc] << endl;
    }
}
