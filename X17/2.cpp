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
	// int d, y;
	// Month m;

	int days; // days since 1.1.1970
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

Date::Date(int dd, Month mm, int yy)
{
	days = 0;
	
	for (int i = 1970; i < yy; i++) {
		//cout << "year:" << i << endl;
		days += (is_leapyear(i) ? 366 : 365);
	}

	for (int i = 1; i < static_cast<int>(mm); i++) {
		//cout << "month:" << i << endl;
		switch (i) {
		case 2:
			days += (28 + is_leapyear(yy));
			break;
		case 4:
		case 6:
		case 9:
		case 11:
			days += 30;
			break;
		case 1:
		case 3:
		case 5:
		case 7:
		case 8:
		case 10:
		case 12:
			days += 31;
			break;
		}
	}

	days += dd;
	
	if (!is_valid()) throw Bad_Date();
}

Date& Date::add_year(int n)
{
	// do not handle negative operation
	if (n < 0) throw Bad_Date();

	int cur_y = year();

	for (int i = 0; i < n; i++) {
		if (is_leapyear(cur_y + n))
			days += 366;
		else
			days += 365;
	}

	return *this;
}

Date& Date::add_month(int n)
{
	int cur_m = static_cast<int>(month());
	int cur_y = year();
	
	for (int i = 0; i < n; i++) {
		switch (i + cur_m) {
		case 2:
			days += (28 + is_leapyear(cur_y));
			break;
		case 4:
		case 6:
		case 9:
		case 11:
			days += 30;
			break;
		case 1:
		case 3:
		case 5:
		case 7:
		case 8:
		case 10:
			days += 31;
			break;
		case 12:
			days += 31;
			cur_y++;
			break;
		}

	}

	return *this;
}

Date& Date::add_day(int n)
{
	days += n;
	return *this;
}

bool Date::is_valid()
{
	return is_date(day(), month(), year());
}

inline int Date::day(void) const
{
	int y = 1970;
	int d = days;
	int m = 1;

	while (d > (365 + is_leapyear(y))) {
		d -= (365 + is_leapyear(y));
		y++;
	}

	while (d > 0) {
		switch (m) {
		case 2:
			if (d <= (28 + is_leapyear(y)))
				goto END;
			d -= (28 + is_leapyear(y));
			break;
		case 4:
		case 6:
		case 9:
		case 11:
			if (d <= 30)
				goto END;
			d -= 30;
			break;
		case 1:
		case 3:
		case 5:
		case 7:
		case 8:
		case 10:
		case 12:
			if (d <= 31)
				goto END;
			d -= 31;
			break;
		}
		m++;
	}
 END:
	return d;
}

inline Month Date::month(void) const
{
	int d = days;
	int m = 1;
	int y = 1970;

	while (d > 0) {
		//cout << "month:" << m << endl;
		switch (m) {
		case 2:
			if (d <= (28 + is_leapyear(y)))
				goto END;
			d -= (28 + is_leapyear(y));
			break;
		case 4:
		case 6:
		case 9:
		case 11:
			d -= 30;
			break;
		case 1:
		case 3:
		case 5:
		case 7:
		case 8:
		case 10:
			if (d <= 30)
				goto END;
			d -= 31;
			break;
		case 12:
			if (d <= 31)
				goto END;
			d -= 31;
			y++;
			break;
		}
		if (d > 0) {
			m++;
			if (m == 13) m = 1;
		}
	}
 END:
	return static_cast<Month>(m);
}

inline int Date::year(void) const
{
	int y = 1970;
	int d = days;

	while (d > (365 + is_leapyear(y))) {
		d -= (365 + is_leapyear(y));
		y++;
	}
	return y;
}

void Date::print(void) const
{
	cout << days << ">>" << day() << ":" << static_cast<int>(month()) << ":" << year() << endl;
}

int main(void)
{
	Date ddd {31, Month::dec, 2019};
	//Date ddd {1, Month::jan, 1970};
	ddd.print();

	for (int i = 0; i <= 366; i++) {
		ddd.add_day(1);
		ddd.print();
	}

	for (int i = 0; i < 14; i++) {
		ddd.add_month(1);
		ddd.print();
	}

	ddd.add_day(40);
	ddd.print();
}
