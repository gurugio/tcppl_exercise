#include <iostream>
#include <cstring>

using namespace std;

#include "MyString.h"

int main()
{
	MyString s ("abcdefghij");
	cout << s << endl;
	s += 'k';
	s += 'l';
	s += 'm';
	s += 'n';
	cout << s << '\n';

	MyString s2 = "Hell";
	s2 += " and high water";
	cout << s2 << '\n';
	MyString s3 = "qwerty";
	s3 = s3;
	MyString s4 ="the quick bro wn fox jumped over the lazy dog";
	s4 = s4;
	cout << s3 << " " << s4 << "\n";
	cout << s + ". " + s3 + MyString(". ") + "Horsefeathers\n";
	MyString buf;
	while (cin>>buf && buf != "quit")
	 	cout << buf << " " << buf.size() << " " << buf.capacity() << '\n';
}
