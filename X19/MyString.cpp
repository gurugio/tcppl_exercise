#include <iostream>
#include <cstring>

using namespace std;

#include "MyString.h"


char* expand(const char*ptr, int n)
{
	char* p = new char[n];
	strcpy(p, ptr);
	return p;
}

void MyString::copy_from(const MyString& x)
{
	
	if (x.sz <= short_max) {
		memcpy(this,&x,sizeof(x));
		ptr = ch;
	} else {
		ptr = expand(x.ptr, x.sz + 1);
		sz = x.sz;
		space = 0;
	}
}

void MyString::move_from(MyString& x)
{
	if (x.sz <= short_max) {
		memcpy(this,&x,sizeof(x));
		ptr = ch;
	} else {
		ptr = x.ptr;
		sz = x.sz;
		space = x.space;
		x.ptr = x.ch;
		x.sz = 0;
		x.ch[0] = 0;
	}
}
	
MyString::MyString(const char* p): sz{static_cast<int>(strlen(p))},
							   ptr{(sz <= short_max) ? ch : new char[sz + 1]},
							   space{0}
{
	strcpy(ptr, p);
}

MyString::MyString(const MyString& x)
{
	copy_from(x);
}

MyString::MyString(MyString&& x)
{
	move_from(x);
}

MyString& MyString::operator=(const MyString& x)
{
	if (this == &x) return *this;
	char *p = (short_max < sz) ? ptr : 0;
	copy_from(x);
	delete[] p;
	return *this;
}

MyString& MyString::operator=(MyString&& x)
{
	if (this == &x) return *this;
	if (short_max < sz) delete[] ptr;
	move_from(x);
	return *this;
}

MyString& MyString::operator+=(char c)
{
	if (sz == short_max) {
		int n = sz + sz + 2;
		ptr = expand(ptr, n);
		space = n - sz - 2;
	} else if (short_max < sz) {
		if (space == 0) {
			int n = sz + sz + 2;
			char* p = expand(ptr, n);
			delete[] ptr;
			ptr = p;
			space = n - sz - 2;
		} else {
			--space;
		}
	}
	ptr[sz] = c;
	ptr[++sz] = 0;
	return *this;
}

ostream& operator<<(ostream& os, const MyString& s)
{
	return os << s.c_str();
}

istream& operator>>(istream& is, MyString& s)
{
	s = "";
	is >> ws; // skip whitespace (§38.4.5.1)
	char ch = ' ';
	while(is.get(ch) && !isspace(ch))
		s += ch;
	return is;
}

bool operator==(const MyString& a, const MyString& b)
{
	if (a.size()!=b.size())
		return false;
	for (int i = 0; i!=a.size(); ++i)
		if (a[i]!=b[i])
			return false;
	return true;
}

bool operator!=(const MyString& a, const MyString& b)
{
	return !(a==b);
}

char* begin(MyString& x)
{
	return x.c_str();
}

char* end(MyString& x)
{
	return x.c_str()+x.size();
}

const char* begin(const MyString& x)
{
	return x.c_str();
}

const char* end(const MyString& x)
{
	return x.c_str()+x.size();
}

MyString& operator+=(MyString& a, const MyString& b)
{
	for (auto x : b)
		a+=x;
	return a;
}

MyString operator+(const MyString& a, const MyString& b) // concatenation
{
	MyString res {a};
	res += b;
	return res;
}

MyString operator"" _s(const char* p, size_t) // suffix _s
{
	return MyString{p};
}

// int main()
// {
// 	MyString s ("abcdefghij");
// 	cout << s << '\n';
// 	s += 'k';
// 	s += 'l';
// 	s += 'm';
// 	s += 'n';
// 	cout << s << '\n';

// 	MyString s2 = "Hell";
// 	s2 += " and high water";
// 	cout << s2 << '\n';
// 	MyString s3 = "qwerty";
// 	s3 = s3;
// 	MyString s4 ="the quick bro wn fox jumped over the lazy dog";
// 	s4 = s4;
// 	cout << s3 << " " << s4 << "\n";
// 	cout << s + ". " + s3 + MyString(". ") + "Horsefeathers\n";
// 	MyString buf;
// 	while (cin>>buf && buf!="quit")
// 		cout << buf << " " << buf.size() << " " << buf.capacity() << '\n';
// }
