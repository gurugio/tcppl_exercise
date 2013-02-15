

#include <iostream>

using namespace std;

class INT {
    int val;
public:

    INT(int n) { val = n; }
    
    INT operator+(int n)
    {
        return INT(val+n);
    }

    INT operator+(INT n)
    {
        return INT(val+n.val);
    }

    friend ostream &operator<<(ostream &os, INT i)
    {
        os << i.val;
        return os;
    }
};


int main(void)
{
    INT x = 3;
    INT y = 4;

    cout << x + 4 + y << endl;


    
}
    
