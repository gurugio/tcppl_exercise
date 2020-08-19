#include <iostream>

using namespace std;

class Vector {
public:
	Vector(int s): size{s} {
		arr = new float[size];
	}
	Vector(float *x, int s): size{s} {
		arr = new float[size];
		for (int i = 0; i < size; i++)
			arr[i] = x[i];
	}

	// default copy initialization is not enought
	// because it must do deep-copy
	Vector(Vector& x): size{x.size} {
		arr = new float[x.size];
		for (int i = 0; i < size; i++)
			arr[i] = x.arr[i];
	}
	Vector& operator=(const Vector& x) {
		cout << this << "=" << &x << endl;
		size = x.size;
		for (int i = 0; i < size; i++)
			arr[i] = x.arr[i];
		return *this;
	}

	Vector& operator+=(Vector& x) {
		cout << this << "+=" << &x << endl;
		
		for (int i = 0; i < size; i++)
			arr[i] += x.arr[i];
		return *this;
	}
	Vector& operator+=(float x) {
		for (int i = 0; i < size; i++)
			arr[i] = x;
		return *this;
	}

	float& operator[](int i) {
		if (i >= size || i < 0) {
			throw out_of_range("operator[]");
		}
		return arr[i];
	}
	friend ostream& operator<<(ostream& os, const Vector& x);
	
private:
	int size;
	float *arr; // MUST have deep-copy initialization
	// default copy initailization copy arr pointer to arr -> one array is shared!
};

Vector operator+(Vector &x, Vector &y)
{
	cout << &x << "+" << &y << endl;
	Vector r{x};
	cout << "r=" << &r << endl;
	r += y;
	cout << "r=" << &r << endl;
	return r;
}

ostream& operator<<(ostream& os, const Vector& x)
{
	os << &x << ":";
	for (int i = 0; i < x.size; i++)
		os << x.arr[i] << ",";
    return os;
}

int main(void)
{
	float arr[5] = {1,2,3,4,5};
	Vector v1{5};
	cout << "v1->" << &v1 << endl;
	v1[0] = arr[0];
	v1[1] = arr[1];
	v1[2] = arr[2];
	v1[3] = arr[3];
	v1[4] = arr[4];
	v1[2] = 99;

	Vector v2{5};
	cout << "v2->" << &v2 << endl;
	v2 = v1;

	cout << "v1+v2:" << v1 + v2 << endl;
	cout << "v1:" << v1 << endl;
	cout << "v2:" << v2 << endl;
}
