#include<iostream>

using namespace std;

typedef int (&rifii)(int, int);

int add(int a, int b)
{
    return a+b;
}

int main(void)
{
    rifii ddd = add;

    cout << ddd(3,4) << endl;
}
