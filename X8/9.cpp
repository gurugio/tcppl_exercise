#include <iostream>

using namespace std;


void f(char a)
{
	cout << a << endl;
}

void g(char& a)
{
	cout << a << endl;
}

void h(const char& a)
{
	cout << a << endl;
}

int main(void)
{
	f('a');
	// g('a');error: cannot bind non-const lvalue reference of type ‘char&’ to an rvalue of type ‘char’
	h('a');

	f(49);
	//g(49); error: cannot bind non-const lvalue reference of type ‘char&’ to an rvalue of type ‘char’
	h(49);

	//f(3300); warning: overflow in conversion from ‘int’ to ‘char’ changes value from ‘3300’ to ‘'\37777777744'’ [-Woverflow]
	//g(3300);warning: overflow in conversion from ‘int’ to ‘char’ changes value from ‘3300’ to ‘'\37777777744'’ [-Woverflow]
	//h(3300);warning: overflow in conversion from ‘int’ to ‘char’ changes value from ‘3300’ to ‘'\37777777744'’ [-Woverflow]

	char c = 'x';
	unsigned char uc = 'x';
	signed char sc = 'x';
	f(c);
	g(c);
	h(c);
	f(uc);
	//g(uc);error: cannot bind non-const lvalue reference of type ‘char&’ to an rvalue of type ‘char’
	h(uc);
	f(sc);
	//g(sc);error: cannot bind non-const lvalue reference of type ‘char&’ to an rvalue of type ‘char’
	h(sc);
}
