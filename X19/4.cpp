#include <iostream>

using namespace std;

class RINT {
public:
	RINT(): n{0} {}
	RINT(int x): n{x} {}
	//RINT(RINT& x): n{x.n} {}

	// RINT& operator=(const RINT& x) {
	// 	n = x.n;
	// 	return *this;
	// }
	RINT& operator=(int& x) {
		n = x;
		return *this;
	}
	
	RINT operator+=(RINT x) {
		n += x.n;
		return *this;
	}
	RINT operator-=(RINT x) {
		n -= x.n;
		return *this;
	}
	RINT operator*=(RINT x) {
		n *= x.n;
		return *this;
	}
	RINT operator/=(RINT x) {
		n /= x.n;
		return *this;
	}
	RINT operator%=(RINT x) {
		n %= x.n;
		return *this;
	}

	friend ostream& operator<<(ostream& os, const RINT& x);
	
private:
	int n;
};

RINT operator+(RINT x, RINT y)
{
	RINT r {x};
	r += y;
	return r;
}
RINT operator-(RINT x, RINT y)
{
	RINT r {x};
	r -= y;
	return r;
}
RINT operator*(RINT x, RINT y)
{
	RINT r {x};
	r *= y;
	return r;

}
RINT operator/(RINT x, RINT y)
{
	RINT r {x};
	r /= y;
	return r;

}
RINT operator%(RINT x, RINT y)
{
	RINT r {x};
	r %= y;
	return r;
}

ostream& operator<<(ostream& os, const RINT& x)
{
	os << x.n;
    return os;
}

int main(void)
{
	RINT n1{1};
	RINT n2 = 2;
	cout << n1 + n2 << endl;
	cout << n1 - n2 << endl;
	cout << n1 * n2 << endl;
	cout << n1 / n2 << endl;

	RINT n3 = 5 % n2;
	cout << n3 << endl;
}
