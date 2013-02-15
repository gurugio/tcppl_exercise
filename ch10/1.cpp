#include <iostream>

using namespace std;

class Date {
    int d, m, y;
public:
    Date(int dd, int mm, int yy) { d = dd, m = mm, y = yy; };

    Date &add_year(int n);

    void print(void) { cout << d << ":" << m << ":" << y << endl; };
};

bool leapyear(int y)
{
    return (y % 4) == 0;
}

Date &Date::add_year(int n)
{
    if (d == 29 && m == 2 && !leapyear(y+n)) {
        d = 1;
        m = 3;
    }

    y += n;
    return *this;
}


int main(void)
{
    Date ddd(29, 2, 2012);

    ddd.add_year(1).print();



}
