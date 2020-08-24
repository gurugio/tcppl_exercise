#include <iostream>
#include <cstring>

using namespace std;

#include "MyString.h"

MyString MyString::operator()(size_t pos, size_t len) {
	MyString r {ptr + pos};
	r[len] = 0;
	return r;
}


int main()
{
	MyString s ("abcdefghij");

	MyString s2 = s(2,4);
	cout << s2 << endl;
}

/*
gkim@gkim-laptop:~/tcppl_exercise/X20$ g++ 3.cpp MyString.cpp && ./a.out
cdef
gkim@gkim-laptop:~/tcppl_exercise/X20$ 
*/
