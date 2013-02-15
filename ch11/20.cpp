#include <iostream>

using namespace std;

struct S { int x, y; };
struct T { char *p; char *q; };

class C {
public:
    struct S sss;
    struct T ttt;
};



int main(void)
{
    C ccc;
    ccc.sss.x = 1;
    cout << ccc.sss.x << endl;
}
