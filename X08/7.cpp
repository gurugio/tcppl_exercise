#include <iostream>

using namespace std;

void swap_intp(int* a, int* b)
{
	int t = *a;
	*a = *b;
	*b = t;
}

void swap_ref(int& a, int &b)
{
	int t = a;
	a = b;
	b = t;
}

int main(void)
{
	int x = 1, y = 2;
	cout << x << y << endl;

	swap_intp(&x, &y);
	cout << x << y << endl;
	swap_ref(x, y);
	cout << x << y << endl;
	return 0;
}
