#include <iostream>

using namespace std;

class Base {
public:
    virtual void iam() { cout << "Base\n"; }
};

class DerivA : public Base {
public:
    void iam() { cout << "DerivA\n"; }
};

class DerivB : public Base {
public:
    void iam() { cout << "DerivB\n"; }
};



int main(void)
{
    Base a;
    DerivA b;
    DerivB c;

    a.iam();
    b.iam();
    c.iam();

    Base *p[] = {&a, &b, &c};

    p[0]->iam();
    p[1]->iam();
    p[2]->iam();


}
    
