#include<iostream>

using namespace std;

long factorial(int x)
{
    long result = 1;
    for (; x > 0; x--)
    {
        result *= x;
        cout << result << ":" << x << endl;
    }
    return result;
}

int main(void)
{

    cout << factorial(10) << endl;
}

