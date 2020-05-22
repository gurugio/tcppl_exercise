#include <iostream>

using namespace std;

int main(void)
{
    cout << "0 & 0 = " << (0 & 0) << endl;
    cout << "0 & 1 = " << (0 & 1) << endl;
    cout << "1 & 0 = " << (1 & 0) << endl;
    cout << "1 & 1 = " << (1 & 1) << endl;

    cout << "0 | 0 = " << (0 or 0) << endl;
    cout << "0 | 1 = " << (0 or 1) << endl;
    cout << "1 | 0 = " << (1 or 0) << endl;
    cout << "1 | 1 = " << (1 or 1) << endl;

    cout << "0 xor 0 = " << (0 xor 0) << endl;
    cout << "0 xor 1 = " << (0 xor 1) << endl;
    cout << "1 xor 0 = " << (1 xor 0) << endl;
    cout << "1 xor 1 = " << (1 xor 1) << endl;

    cout << "3 and 4 = " << (3 and 4) << endl;
    cout << "3 bitand 4 = " << (3 bitand 4) << endl;
}