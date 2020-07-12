#include <iostream>

using namespace std;


#define PI = 3.141593;
#define MAX(a,b) a>b?a:b
#define fac(a) (a)*fac(a-1)

int main(void)
{
	// cout << PI << endl; ->  compile error because of ; -> cout << = 3.141593; << endl;

	// cout << MAX(1+2, 3+4) << endl; //-> compile error -> operation priority
	// -> cout << 1+2>3+4?1+2:3+4 << endl;

	fac(5); // compile error: macro cannot be recusive
/*	15.cpp: In function ‘int main()’:
15.cpp:8:20: error: ‘fac’ was not declared in this scope
    8 | #define fac(a) (a)*fac(a-1)
      |                    ^~~
15.cpp:17:2: note: in expansion of macro ‘fac’
   17 |  fac(5);
      |  ^~~
*/
	
	return 0;
}









