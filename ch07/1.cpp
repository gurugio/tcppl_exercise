#include<iostream>

using namespace std;


void f1(char *pa, int &ri)
{
    cout << pa << ri << endl;
    ri++;
}

typedef void (*pf)(char *pa, int &ri);

void f2(pf af)
{
    cout << "run f1 with <hello again:, 54321>" << endl;

    char msg[] = "hello again:";
    int data = 54321;
    af(msg, data);
}

pf f3(void)
{
    return f1;
}

pf f4(pf af)
{
    return af;
}


int main(void)
{
    char msg[] = "hello:";
    int data = 12345;

    f1(msg, data);

    cout << "data increased to:" << data << endl;

    f2(f1);

    (*f3())(msg, data);

    (*f4(f1))(msg, data);
}
