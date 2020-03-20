#include <iostream>
#include <string>
#include <vector>

using namespace std;

	
struct entry
{
	string name;
	int age;
};
	
class name_age
{
public:
	vector<entry> book;
};

ostream& operator<<(ostream& os, const name_age& na)
{
	string output;
	for (auto e: na.book)
		output += "{\"" + e.name + "\", " + to_string(e.age) + "}" + "\n";
	return os << output;
}

istream& operator>>(istream& is, name_age& na)
{
	// input format: {"first second", digits}
	char c, c2;

	if (is >> c && c == '{' && is >> c2 && c2 == '"') {
		string name;

		// read characters between "..."
		while (is.get(c) && c != '"')
			name += c;

		if (is >> c && c == ',') {
			int number = 0;

			if (is >> number >> c && c == '}') {
				cout << "new entry: " << name << ":" << number << endl;
				entry e = {name, number};
				na.book.push_back(e);
				return is;
			}
		}
	}
	is.setstate(ios::failbit);
	cout << "wrong format\n";
	return is;
}

int main(void)
{
	for (name_age na_book; cin >> na_book; )
		cout << na_book;
}
