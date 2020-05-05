#include <iostream>
#include <string>

using namespace std;


const char *months[] = {"Jan", "Feb", "Mar", "Apr"}; // const removes a compile warning
int days[] = {31, 28, 31, 30};

struct each_month {
	string name;
	int day;
};

struct each_month calendar[] = {
	{"Jan", 31},
	{"Feb", 28},
	{"Mar", 31},
	{"Apr", 30}
};

int main(void)
{
	for (int i = 0; i < 4; i++) {
		cout << months[i] << days[i] << endl;
		cout << calendar[i].name << calendar[i].day << endl;
	}
}
