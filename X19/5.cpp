#include <iostream>

using namespace std;

class LINT {
public:
	LINT(): n{0} {}
	LINT(uint64_t x): n{x} {}
	
	operator uint64_t() {
		return n;
	}
	
private:
	uint64_t n;
};

void print_int(int x)
{
	cout << x << endl;
}

int main(void)
{
	LINT n1 = 1;
	LINT n2 = 2;
	uint64_t n3 {n1 + n2};

	cout << 4 + n1 + n2 + 3 << endl;
	print_int(n1 * 2);
	print_int(n1 + n2);
	print_int(n1 + 3);

	cout << n3 << endl;
	n2 = 0x1234567812345678;
	cout << hex << n2 << endl;
}
