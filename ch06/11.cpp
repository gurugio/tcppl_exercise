#include <iostream>



using namespace std;

void f(int a, int b)
{
    if (a = 3)
        cout << "a is 3" << endl;

    if (a & 077 == 0)
        cout << "a & 077 == 0 is true!" << endl;

// a := b+1; 11.cpp:15:4: error: expected primary-expression before ‘=’ token
    
}

int main(void)
{
    f(3, 4);

    f(7, 7);
    
}
