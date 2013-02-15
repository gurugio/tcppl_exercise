#include <iostream>
#include <string>


using namespace std;



void f(char a)
{
    cout << a << '\n';
}

void g(char& ra)
{
    cout << ra << '\n';
}

void h(const char& cra)
{
    cout << cra << '\n';
}

int main(void)
{
    char c = 'x';
    unsigned char uc = 0xff;
    signed char sc = -1;
    
    f('a');
    f(49);
    f(3300); // 6.cpp:32:11: warning: overflow in implicit constant conversion [-Woverflow]
    f(c);
    f(uc);
    f(sc);

    g('a'); // 6.cpp:37:10: error: invalid initialization of non-const reference of type ‘char&’ from an rvalue of type ‘char’
    g(49); //6.cpp:38:9: error: invalid initialization of non-const reference of type ‘char&’ from an rvalue of type ‘int’
    g(3300); //6.cpp:39:11: error: invalid initialization of non-const reference of type ‘char&’ from an rvalue of type ‘int’
    g(c);
    g(uc); //6.cpp:41:9: error: invalid initialization of reference of type ‘char&’ from expression of type ‘unsigned char’
    g(sc); //6.cpp:42:9: error: invalid initialization of reference of type ‘char&’ from expression of type ‘signed char’

    h('a');
    h(49);
    h(3300); //6.cpp:46:11: warning: overflow in implicit constant conversion [-Woverflow]
    h(c);
    h(uc);
    h(sc);

    

    
    return 0;
}
