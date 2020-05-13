#include <iostream>
#include <limits>

using namespace std;


#define MAX(type) __alignof__(numeric_limits<type>::max())
#define MIN(type) __alignof__(numeric_limits<type>::min())

int main(void)
{
	cout << "type: min : max\n";
	cout << hex;
	cout << "bool:" << __alignof__(numeric_limits<bool>::min()) << " " << __alignof__(numeric_limits<bool>::max()) << endl;
	cout << "char:" << __alignof__(numeric_limits<char>::min()) << " " << __alignof__(numeric_limits<char>::max()) << endl;
	cout << "short:" << __alignof__(numeric_limits<short>::min()) << " " << __alignof__(numeric_limits<short>::max()) << endl;
	cout << "int:" << __alignof__(numeric_limits<int>::min()) << " " << sizeof(numeric_limits<int>::max()) << endl;
	cout << "long:" << MIN(long) << ":" << MAX(long) << endl;
	cout << "long long:" << MIN(long long) << ":" << MAX(long long) << endl;
	cout << "float:" << MIN(float) << ":" << MAX(float) << endl;
	cout << "double:" << MIN(double) << ":" << MAX(double) << endl;
	cout << "long double:" << MIN(long double) << ":" << MAX(long double) << endl;
	cout << "unsigned:" << MIN(unsigned) << ":" << MAX(unsigned) << endl;
	cout << "unsigned long:" << MIN(unsigned long) << ":" << MAX(unsigned long) << endl;

	return 0;
}
