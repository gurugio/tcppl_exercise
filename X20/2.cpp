#include <iostream>
#include <cstring>

using namespace std;

#include "MyString.h"


class String_iter {
	char* p;
public:
	String_iter(MyString& s): p{s.c_str()} {}
	char& next() {
		return *(p++);
	}

	bool operator==(String_iter& rhs) { return rhs.p == p; }
	bool operator!=(String_iter& rhs) { return !(rhs == *this); }
};

int main()
{
	MyString s ("abcdefghij");
	String_iter iter {s};

	cout << "use external-iterator\n";
	for (char c = iter.next(); c != '\0'; c = iter.next())
		cout << c << endl;

	cout << "use internal-iterator\n";
	for (auto c: s)
		cout << c << endl;
}

/*
gkim@gkim-laptop:~/tcppl_exercise/X20$ g++ 2.cpp MyString.cpp && ./a.out
a
b
c
d
e
f
g
h
i
j
*/
