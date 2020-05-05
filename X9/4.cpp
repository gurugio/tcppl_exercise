#include <iostream>

using namespace std;

struct Date {
	string name;
};

ostream& operator<<(ostream& os, Date& d)
{
	os << "Today is " << d.name << endl;
	return os;
}

istream& operator>>(istream&is, Date& d)
{
	cout << "Enter date of today: ";
	is >> d.name;
	return is;
}

void date(Date& d, string to)
{
	d.name = to;
}

int main(void)
{
	struct Date today;
	date(today, "monday");
	cout << today;
	cin >> today;
	cout << today;
}
