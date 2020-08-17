#include <iostream>

using namespace std;

class Int {
public:
	Int(): n{0} {}
	Int(int x): n{x} {}
	
	operator int() {
		return n;
	}
	
private:
	int n;
};

void print_int(int x)
{
	cout << x << endl;
}

int main(void)
{
	Int n1 = 1;
	Int n2 = 2;
	int n3 {n1 + n2};

	cout << 4 + n1 + n2 + 3 << endl;
	print_int(n1 * 2);
	print_int(n1 + n2);
	print_int(n1 + 3);

	cout << n3 << endl;
}
