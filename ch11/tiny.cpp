#include <iostream>
#include <cstdio>

using namespace std;

class Tiny {
    char v;
    void assign(int i)
    {
        if (i & ~077)
            throw Bad_range();
        v = i;
    }

public:
    class Bad_range{};

    Tiny(int i) { cout << "const\n"; assign(i); }
    Tiny &operator=(int i) { cout << "assign\n"; assign(i); return *this; }

    operator int() const {
        cout << "operator-int\n";
        return v;
    }

    void show(void) { cout << v << endl; }

    friend ostream &operator<<(ostream &os, Tiny x);
};


ostream &operator<<(ostream &os, Tiny x)
{
//    os.write("go\n", 2);
    os << (int)(x.v);
    return os;
}

int main(void)
{
    Tiny c1 = 2;
    Tiny c2 = 62;
    Tiny c3 = c2 - c1;
    Tiny c4 = c3;
    int i = c1 + c2;


    cout << c2 << endl;

    cout << c2 + 3 << endl;
    cout << 3 + c2 << endl;
    cout << 3 + c2 * 2 - 1 << endl;
    
}
