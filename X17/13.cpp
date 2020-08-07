#include <iostream>
#include <string>

using namespace std;

class Mystring: public string
{
public:
	Mystring(const char* s): as{s} {
		cout << "initalize\n";
	}
	~Mystring() {
		cout << "clean up\n";
	}

	friend ostream& operator<<(ostream& os, Mystring& s);
	
private:
	string as;
};

ostream& operator<<(ostream& os, Mystring& s)
{
	cout << string {"overloaded operator<< of Mystring"} << endl;

	cout << s.as;
	return os;
}

ostream& operator<<(ostream& os, const char* s)
{
	cout << string {"overloaded operator<< of const char*"} << endl;

	Mystring dd {s};
	os << dd;
	return os;
}


int main()
{
	std::cout << "Hello, world!\n";
}
