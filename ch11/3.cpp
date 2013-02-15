

#include <iostream>

using namespace std;

class INT {
    int val;
public:

    INT(int n) { val = n; }
    
    operator int() const
    {
        cout << "Y::int()\n";
        return val;
    }

};


int main(void)
{
    INT x = 3;
    INT y = 4;

    cout << x+y << endl;
    cout << x-y << endl;
    cout << x*y << endl;
    cout << x/y << endl;

    cout << x+4 << endl;
    cout << x-4 << endl;
    cout << x*3 << endl;
    cout << x/4 << endl;

    cout << 4 - x << endl;
    
}
    
