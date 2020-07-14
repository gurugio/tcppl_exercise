#include <iostream>
#include <string>

using namespace std;

int day_in_month[13] = {0,
						31, 29, 31, 30, 31, 30,
						31, 31, 30, 31, 30, 31}; 
string MONTH[13] = {"",
					"JAN",
					"FEB",
					"MAR",
					"APR",
					"MAY",
					"JUN",
					"JUL",
					"AUG",
					"SEP",
					"OCT",
					"NOV",
					"DEC"};
string DAY[8] = {"",
				 "SUN",
				 "MON",
				 "TUE",
				 "WED",
				 "TUH",
				 "FRI",
				 "SAT"};

class Date {
public:
	Date(string s) {
		year = stoi(s.substr(0, 4));
		month = stoi(s.substr(5, 2));
		day = stoi(s.substr(8,2));
	}
	Date(): year(2020), month(1), day(1) {}

	int year;
	int month;
	int day;
};

void date(Date& d, string to)
{
	/* to-> yyyy:mm:dd */
	d.year = stoi(to.substr(0, 4));
	d.month = stoi(to.substr(5, 2));
	d.day = stoi(to.substr(8,2));
}

ostream& operator<<(ostream& os, Date& d)
{
	os << d.year << ":" << MONTH[d.month] << ":" << d.day;
	return os;
}

istream& operator>>(istream&is, Date& d)
{
	string input;
	cout << "Enter date of today (yyyy:mm:dd):";
	is >> input;
	date(d, input);
	return is;
}

string date_to_day(Date d)
{
	/* BUGBUG: only support 2020 */
	int day = 3; // 2020.01.01 is Wednesday
	for (int i = 0; i < d.month; i++) {
		day += day_in_month[i];
	}
	day += d.day;
	return DAY[day % 7];
}

Date next_year(Date& d)
{
	Date next = d;
	next.year++;
	return next;
}

Date next_month(Date& d)
{
	Date next = d;
	next.month++;
	if (next.month > 12) {
		next = next_year(next);
		next.month = 1;
	}
	return next;
}

Date next_day(Date& d)
{
	Date next = d;
	next.day++;
	if (next.day > day_in_month[next.month]) {
		next.day = 1;
		next = next_month(next);
	}	
	return next;
}

int main(void)
{
	Date today("2020:12:31");
	cout << today << endl;

	cout << date_to_day(Date{"2020:04:01"}) << endl; // WED
	cout << date_to_day(Date{"2020:05:01"}) << endl; // FRI
	cout << date_to_day(Date{"2020:07:7"}) << endl; // TUE
	cout << date_to_day(Date{"2020:07:14"}) << endl; // TUE

	Date next = next_year(today);
	cout << "next year:" << next << endl;
	next = next_month(next);
	cout << "next month:" << next << endl;
	next = next_day(next);
	cout << "next day:" << next << endl;
}
