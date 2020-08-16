#include <iostream>

using namespace std;


struct X {
	int i;
	X(int n) {
		cout << "x-constructor: " << n << endl;
		i = n;
	}
	X operator+=(int n) {
		cout << "x-operator+=:" << n << endl;
		i += n;
		return *this;
	}
	X operator+(int n) {
		X xx{i};
		cout << "x-operator+:" << n << endl;
		return xx += n;
	}
};

struct Y {
	int i;
	Y(X xx) {
		cout << "y-constructor: " << xx.i << endl;
		i = xx.i;
	}
	Y operator+(X xx) {
		Y yy{i + xx.i};
		cout << "y-operator+:" << xx.i << endl;
		return yy;
	}
	operator int() {
		cout << "y-conversion-int:" << i << endl;
		return i;
	}
	Y operator+=(int n) {
		cout << "y-operator+int:" << n << endl;
		i += n;
		return *this;
	}
	Y operator*=(int n) {
		cout << "y-operator*int:" << n << endl;
		i *= n;
		return *this;
	}
};

ostream& operator<<(ostream& os, const X& xx)
{
	os << xx.i;
    return os;
}

extern X operator*(X xx, Y yy)
{
	cout << "operator*-xy" << endl;
	return X{xx.i * yy.i};
}

// ambiguouty: x + int, int + y
// extern X operator+(X xx, Y yy)
// {
// 	cout << "operator+-xy" << endl;
// 	return X{xx.i + yy.i};
// }

extern int operator+(Y yy, int n)
{
	cout << "operator y+int:" << yy.i << " " << n << endl;
	return yy.i + n;
}

extern int operator*(int n, Y yy)
{
	cout << "operator y*int:" << yy.i << " " << n << endl;
	return yy.i * n;
}

extern int f(X xx)
{
	// no conversion X to int
	return xx.i + 1;
}

extern int f(int n)
{
	return n + 1;
}

X x = 1;
Y y = x;
int i = 2;

int main()
{
	cout << i + 10 << endl;

	//operator y+int:1 10
	//11
	cout << y + 10 << endl; 

	//operator y*int:1 10
	//operator y+int:1 10
	//11
	cout << y + 10 * y << endl;

// y-conversion-int:1
// x-constructor: 1
// x-operator+:1
// x-operator+=:1
// x-constructor: 2
// x-operator+:2
// x-operator+=:2
	//4
	cout << x + y + i << endl;

// y-constructor: 1
// operator*-xy
// x-constructor: 1
// x-constructor: 1
// x-operator+:2
// x-operator+=:2
// 3
	cout << x * x + i << endl;

	// x-constructor: 7
	f(7);
	// y-conversion-int:1
	f(y);

	// y-conversion-int:1
	// operator y+int:1 1
	cout << y + y << endl;

	// y-conversion-int:1
	cout << 106 + y << endl;
}
