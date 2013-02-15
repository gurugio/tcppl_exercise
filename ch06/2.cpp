#include <iostream>

using namespace std;

int main(void)
{
    int a = 1, b = 2, c = 3, d = 4;
    
    a = b + c * d << 2 & 8;
    cout << a << endl;
    
    a = ((b + (c * d)) << 2) & 8;
    cout << a << endl;

    
    if (a & 077 != 3)
        cout << (a & 077) << endl;
    
    if (a & (077 != 3))
        cout << (a & 077) << endl;
        
    a = b;
    if (a == b || a == c && c < 5)
        cout << "t" << endl;

    if ((a == b || a == c) && c < 5)
        cout << "t" << endl;

    int x = 1;
    cout << (c = x != 0) << endl;
    cout << (c = (x != 0)) << endl;
    /*
0 <= i < 7

f(1 2)+3
a = - 1 + + b -- - 5
a = b == c ++
a=b=c=0
a 4][2 *= * b ? c : * d * 2
a[4 2]
a b,c d
a-b c=d
    */

    return 0;
}
