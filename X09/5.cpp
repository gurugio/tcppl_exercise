#include <iostream>

using namespace std;

enum class Season {
	spring,
	summer,
	autumn,
	winter
};

enum class SeasonFormat {
	english,
	german
};

SeasonFormat cur_format = SeasonFormat::english;

string eng_seasons[4] = {"Spring", "Summer", "Autumn", "Winter"};
string ger_seasons[4] = {"Frueling", "Sommer", "Herbst", "Winter"};

ostream& operator<<(ostream& os, SeasonFormat f)
{
	if (f == SeasonFormat::english) {
		cout << "Use English\n";
		cur_format = SeasonFormat::english;
	} else if (f == SeasonFormat::german) {
		cout << "Use German\n";
		cur_format = SeasonFormat::german;
	}
	return os;
}

ostream& operator<<(ostream& os, Season s)
{
	string *exp;
	if (cur_format == SeasonFormat::english)
		exp = eng_seasons;
	else if (cur_format == SeasonFormat::german)
		exp = ger_seasons;
	
	switch (s) {
	case Season::spring:
		os << exp[0];
		break;
	case Season::summer:
		os << exp[1];
		break;
	case Season::autumn:
		os << exp[2];
		break;
	case Season::winter:
		os << exp[3];
		break;
	}
	return os;
}

istream& operator>>(istream& is, Season& s)
{
	int input;
	cout << "Enter season(1-4): ";
	cin >> input;
	switch (input) {
	case 1:
		s = Season::spring;
		break;
	case 2:
		s = Season::summer;
		break;
	case 3:
		s = Season::autumn;
		break;
	case 4:
		s = Season::winter;
		break;
	}
	return is;
}

int main(void)
{
	cout << "test ostream" << endl;
	cout << Season::spring << endl;
	cout << Season::autumn << endl;

	Season now;
	cin >> now;
	cout << "In English: " << now << endl;

	SeasonFormat format = SeasonFormat::german;
	cout << format;
	cout << "In German: " << now << endl;
}
