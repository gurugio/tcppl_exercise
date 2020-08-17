#ifndef MYSTRING_H
#define MYSTRING_H

#include <iostream>

class MyString
{
public:
	MyString(): sz{0}, ptr{ch} {
		ch[0] = 0;
	}
	
	MyString(const char* p);
	MyString(const MyString& s); //copy constructor
	MyString& operator=(const MyString& s); //copy assignment

	MyString(MyString&& x); // move constructor
	MyString& operator=(MyString&& x); // move assignment

	~MyString() { if (short_max < sz) delete[] ptr; }

	char& operator[](int n) { return ptr[n]; }
	char operator[](int n) const { return ptr[n]; }

	char& at(int n) { check(n); return ptr[n]; }
	char at(int n) const { check(n); return ptr[n]; }

	MyString& operator+=(char c);

	char* c_str() { return ptr; }
	const char* c_str() const { return ptr; }

	int size() const { return sz; }
	int capacity() const
		{ return (sz <= short_max) ? short_max : sz+space; }

	friend ostream& operator<<(ostream& os, const MyString& s);
	friend istream& operator>>(istream& is, MyString& s);
	friend MyString& operator+=(MyString& a, const MyString& b);
	friend MyString operator+(const MyString& a, const MyString& b); // concatenation
	friend bool operator==(const MyString& a, const MyString& b);
	friend bool operator!=(const MyString& a, const MyString& b);

private:
	static const int short_max = 15;
	int sz;
	char* ptr;
	union {
		int space;
		char ch[short_max + 1];
	};

	void check(int n) const {
		if (n < 0 || sz <= n)
			throw std::out_of_range("MyString::at()");
	}

	void copy_from(const MyString& x);
	void move_from(MyString& x);
};

//extern ostream& operator<<(ostream& os, const MyString& s);

#endif
