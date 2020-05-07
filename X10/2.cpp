#include <iostream>

using namespace std;


/* compile warnings from g++
gkim@laptop:~/tcppl_exercise/X10$ g++ -Wall 2.cpp
2.cpp: In function ‘void f(int, int)’:
2.cpp:8:8: warning: suggest parentheses around assignment used as truth value [-Wparentheses]
    8 |  if (a = 3) cout << a << endl;
      |      ~~^~~
2.cpp:9:12: warning: suggest parentheses around comparison in operand of ‘&’ [-Wparentheses]
    9 |  if (a&077 == 0)  cout << a << endl;
      |        ~~~~^~~~
gkim@laptop:~/tcppl_exercise/X10$
*/

void f(int a, int b)
{
	if (a = 3) cout << a << endl;
	if (a&077 == 0)  cout << a << endl;
	// a := b+1; //2.cpp:10:5: error: expected primary-expression before ‘=’ token
}

int main(void)
{
	f(4,4); // should've print 4 but 3
	f(0,4); // should've print 0 but 3
}
