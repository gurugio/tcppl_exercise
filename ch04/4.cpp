#include <iostream>
using namespace std;

int main(void)
{

    for (char c = 'a'; c <= 'z'; c++)
    {
        cout << c << "->" << int(c) << '\n';
    }

    for (char c = '0'; c <= '9'; c++)
    {
        cout << c << "->" << int(c) << '\n';
    }

    for (char c = 'a'; c <= 'z'; c++)
    {
        cout << c << "->0x" << hex << int(c) << '\n';
    }

    for (char c = '0'; c <= '9'; c++)
    {
        cout << c << "->0x" << hex << int(c) << '\n';
    }


    return 0;
}
