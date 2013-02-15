#include <iostream>

using namespace std;

class Vec4 {
private:
    float v[4];

public:
    Vec4(float v0 = 0, float v1 = 0, float v2 = 0, float v3 = 0)
    { v[0] = v0, v[1] = v1, v[2] = v2, v[3] = v3; }
    
    class Bad_range {};

    void check(int i) const { if (i < 0 || i >= 4) throw Bad_range(); }
    
    float operator[](int i) const { check(i); return v[i]; }

    Vec4 &operator+=(float val) { v[0]+=val, v[1]+=val, v[2]+=val, v[3]+=val; return *this; }
    Vec4 &operator-=(float val) { v[0]-=val, v[1]-=val, v[2]-=val, v[3]-=val; return *this; }
    Vec4 &operator*=(float val) { v[0]*=val, v[1]*=val, v[2]*=val, v[3]*=val; return *this; }
    Vec4 &operator/=(float val) { v[0]/=val, v[1]/=val, v[2]/=val, v[3]/=val; return *this; }

    friend ostream &operator<<(ostream &os, const Vec4 &vec);
    
};

Vec4 operator+(const Vec4 vec, float val)
{
    Vec4 temp = vec;
    temp += val;
    return temp;
}

Vec4 operator-(const Vec4 vec, float val)
{
    Vec4 temp = vec;
    temp -= val;
    return temp;
}

Vec4 operator*(const Vec4 vec, float val)
{
    Vec4 temp = vec;
    temp *= val;
    return temp;
}

Vec4 operator/(const Vec4 vec, float val)
{
    Vec4 temp = vec;
    temp /= val;
    return temp;
}

ostream &operator<<(ostream &os, const Vec4 &vec)
{
    os << vec.v[0] << ',' << vec.v[1] << ',' << vec.v[2] << ',' << vec.v[3];
    return os;
}


int main(void)
{
    Vec4 v(1, 2, 3, 4);

    cout << v[1] << v[2] << endl;
    cout << v << endl;

    v += 3;
    cout << v << endl;

    v *= 2;
    cout << v << endl;

    Vec4 v2 = v + 3;
    
    cout << v+3 << endl;

    cout << v * 3 << endl;
}
