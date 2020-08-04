#include <iostream>

using namespace std;

enum class Month { jan=1, feb, mar, apr, may, jun, jul, aug, sep, oct, nov, dec };

class Date {
public:
	class Bad_Date {};
	
	explicit Date(int dd ={}, Month mm ={}, int yy ={});

	inline int day() const;
	inline Month month() const;
	inline int year() const;

	string string_rep() const;
	void char_rep(char s[], int max) const;
	
	Date& add_day(int n);
	Date& add_month(int n);
	Date& add_year(int n);

	void print(void) const;
private:
	bool is_valid();
	int d, y;
	Month m;
};

bool is_leapyear(int y)
{
	return y % 4 == 0;
}

bool is_date(int d, Month m, int y)
{
	int ndays;

	switch (m) {
	case Month::feb:
		ndays = 28 + is_leapyear(y);
		break;
	case Month::apr: case Month::jun: case Month::sep: case Month::nov:
		ndays = 30;
		break;
	case Month::jan: case Month::mar: case Month::may: case Month::jul:
	case Month::aug: case Month::oct: case Month::dec:
		ndays = 31;
		break;
	default:
		return false;
	}
	return 1 <= d && d <= ndays;
}

const Date& default_date()
{
	static Date d {1, Month::jan, 1970};
	return d;
}

Date::Date(int dd, Month mm, int yy): d{dd}, m{mm}, y{yy}
{
	if (y == 0) y = default_date().year();
	if (m == Month{}) m = default_date().month();
	if (d == 0) d = default_date().day();

	if (!is_valid()) throw Bad_Date();
}

Date& Date::add_year(int n)
{
	// do not handle negative operation
	if (n < 0) throw Bad_Date();
	
	if (d == 29 && m == Month::feb && !is_leapyear(y + n)) {
		d = 1;
		m = Month::mar;
	}

	y += n;
	return *this;
}

Date& Date::add_month(int n)
{
	if (n > 0) {
		int delta_y = n / 12;
		int mm = static_cast<int>(m) + n % 12;
		if (12 < mm) {
			delta_y++;
			mm -= 12;
		}

		add_year(delta_y); // handle the leapyear case
		m = static_cast<Month>(mm);
	} else if (n < 0) {
		throw Bad_Date(); // do not handle negative operation
	} else {
		/* do nothing if n == 0 */
	}
	return *this;
}

Date& Date::add_day(int n)
{
	int ndays;

	n += d;
	
	while (n > 0) {
		switch (m) {
		case Month::feb:
			ndays = 28 + is_leapyear(y);
			break;
		case Month::apr: case Month::jun: case Month::sep: case Month::nov:
			ndays = 30;
			break;
		case Month::jan: case Month::mar: case Month::may: case Month::jul:
		case Month::aug: case Month::oct: case Month::dec:
			ndays = 31;
			break;
		}

		if (n > ndays) {
			n -= ndays;
			add_month(1);
		} else {
			break;
		}
	}

	d = n;
	
	return *this;
}

bool Date::is_valid()
{
	return is_date(d, m, y);
}

inline int Date::day(void) const
{
	return d;
}

inline Month Date::month(void) const
{
	return m;
}

inline int Date::year(void) const
{
	return y;
}

void Date::print(void) const
{
	cout << d << ":" << static_cast<int>(m) << ":" << y << endl;
}

int main(void)
{
	Date ddd {31, Month::dec, 2019};

	for (int i = 0; i < 200; i++) {
		ddd.add_day(1);
		ddd.print();
	}

	for (int i = 0; i < 100; i++) {
		ddd.add_month(1);
		ddd.print();
	}

	ddd.add_day(40);
	ddd.print();
}
