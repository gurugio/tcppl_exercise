#include <iostream>

using namespace std;

struct overflow
{
    string *msg;
    overflow() { msg = new string("overflow"); };
};

struct underflow
{
    string *msg;
    underflow() { msg = new string("underflow"); };    
};

int myplus(int a, int b)
{
    if ((numeric_limits<int>::max() - a) > b)
    {
        return a+b;
    }
    else
    {
        throw overflow();
    }
}

int myminus(int a, int b)
{
    if (a > b)
    {
        return a - b;   
    }
    else
    {
        throw underflow();
    }
}

int main(int argc, char* argv[])
{
    try
    {
        cout << myplus(0x7ffffff0, 0xff) << endl;
    }
    catch (overflow e)
    {
        cout << *e.msg << endl;    
    }

    try
    {
        cout << myminus(0xf0, 0xff) << endl;
    }
    catch (underflow e)
    {
        cout << *e.msg << endl;    
    }
}

