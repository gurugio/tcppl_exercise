#include <iostream>
using namespace std;

int main(void)
{
    cout << sizeof(int) << sizeof(long int) << sizeof(long long) << sizeof(double) << '\n';
    cout << sizeof(int *) << sizeof(void *) << '\n';

    enum ab { AAA, BBB, CCC };
    cout << sizeof(ab) << sizeof(AAA) << '\n';
}
