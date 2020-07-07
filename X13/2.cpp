#include <iostream>

using namespace std;


using riffi = int (&) (int, int);

int func(int a, int b)
{
	return a+b;
}

int main(void)
{
	// It is a normal function pointer?
	// What is it good for?
	riffi fptr = func;

	cout << fptr(3,4) << endl;
	return 0;
}
