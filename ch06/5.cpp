#include <iostream>


using namespace std;


int and_table[2][2] = {
    {0, 0},
    {0, 1}
};

int main(void)
{

    // undefined
    unsigned char a = 'a'+255;
    unsigned short b = 65536;
    unsigned long c = 0xfffffffffffffffff;
    and_table[2][2] = c;

    cout << a << endl << b << endl << c << endl << and_table[2][2] << endl;

    // defined
    a = 'a';
    b = 0xffff;
    c = 0xffffffffffffffff;
    and_table[1][1] = c;
    
    cout << a << endl << b << endl << c << endl << and_table[2][2] << endl;

    return 0;
}
