#include <iostream>
#include <cstring>


using namespace std;

class Int
{
public:
	int val;

	Int(int x): val{x} {}
	Int() : val{0} {}

	int operator+(int x) {
		if ((val + x) < val) {
			throw runtime_error{"Int: overflow"};
		}
		val += x;
		return val;
	}

	int operator-(int x) {
		if ((val - x) > val) {
			cout << static_cast<int>(val - x) << endl;
			throw runtime_error{"Int: underflow"};
		}
		val -= x;
		return val;
	}

	friend ostream& operator<<(ostream& os, const Int& x);
};

ostream& operator<<(ostream& os, const Int& x)
{
	os << x.val;
	return os;
}


int main(void)
{
	Int a = 3;
	a = a + 2;
	cout << a << endl;

	// overflow
	// a = a + 0xffffffff;
	// cout << a << endl;;

	// underflow
	a = a - 0xffffffff;
	cout << a << endl;
	
}
