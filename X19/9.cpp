#include <iostream>

using namespace std;

class Vec4 {
public:
	Vec4(float x) {
		arr[0] = arr[1] = arr[2] = arr[3] = x;
	}
	Vec4(float x[4]) {
		arr[0] = x[0];
		arr[1] = x[1];
		arr[2] = x[2];
		arr[3] = x[3];
	}
	Vec4& operator=(float x[4]) {
		arr[0] = x[0];
		arr[1] = x[1];
		arr[2] = x[2];
		arr[3] = x[3];
		return *this;
	}
	
	Vec4 operator+=(Vec4 x) {
		arr[0] += x.arr[0];
		arr[1] += x.arr[1];
		arr[2] += x.arr[2];
		arr[3] += x.arr[3];
		return *this;
	}
	Vec4 operator+=(float x) {
		arr[0] += x;
		arr[1] += x;
		arr[2] += x;
		arr[3] += x;
		return *this;
	}
	Vec4 operator-=(Vec4 x) {
		arr[0] -= x.arr[0];
		arr[1] -= x.arr[1];
		arr[2] -= x.arr[2];
		arr[3] -= x.arr[3];
		return *this;
	}
	Vec4 operator-=(float x) {
		arr[0] -= x;
		arr[1] -= x;
		arr[2] -= x;
		arr[3] -= x;
		return *this;
	}
	Vec4 operator*=(Vec4 x) {
		arr[0] *= x.arr[0];
		arr[1] *= x.arr[1];
		arr[2] *= x.arr[2];
		arr[3] *= x.arr[3];
		return *this;
	}
	Vec4 operator*=(float x) {
		arr[0] *= x;
		arr[1] *= x;
		arr[2] *= x;
		arr[3] *= x;
		return *this;
	}
	Vec4 operator/=(Vec4 x) {
		arr[0] /= x.arr[0];
		arr[1] /= x.arr[1];
		arr[2] /= x.arr[2];
		arr[3] /= x.arr[3];
		return *this;
	}
	Vec4 operator/=(float x) {
		arr[0] /= x;
		arr[1] /= x;
		arr[2] /= x;
		arr[3] /= x;
		return *this;
	}

	float& operator[](int i) {
		if (i >= 4 || i < 0) {
			throw out_of_range("operator[]");
		}
		return arr[i];
	}

	friend ostream& operator<<(ostream& os, const Vec4& x);
	
private:
	float arr[4];

};

Vec4 operator+(Vec4 x, Vec4 y)
{
	Vec4 r {x};
	r += y;
	return r;
}
Vec4 operator-(Vec4 x, Vec4 y)
{
	Vec4 r {x};
	r -= y;
	return r;
}
Vec4 operator*(Vec4 x, Vec4 y)
{
	Vec4 r {x};
	r *= y;
	return r;
}
Vec4 operator/(Vec4 x, Vec4 y)
{
	Vec4 r {x};
	r /= y;
	return r;
}

Vec4 operator+(Vec4 x, float y)
{
	Vec4 r {x};
	r += y;
	return r;
}
Vec4 operator-(Vec4 x, float y)
{
	Vec4 r {x};
	r -= y;
	return r;
}
Vec4 operator*(Vec4 x, float y)
{
	Vec4 r {x};
	r *= y;
	return r;
}
Vec4 operator/(Vec4 x, float y)
{
	Vec4 r {x};
	r /= y;
	return r;
}

ostream& operator<<(ostream& os, const Vec4& x)
{
	os << "Vec4:" << x.arr[0] << "," << x.arr[1] << "," << x.arr[2] << "," << x.arr[3];
    return os;
}

int main(void)
{
	float arr[4] = {1,2,3,4};
	Vec4 v1 = arr;

	cout << v1 * 3 << endl;
	v1[2] = 99;
	cout << v1 << endl;
}
