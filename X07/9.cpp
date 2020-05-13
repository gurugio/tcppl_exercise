#include <iostream>
#include <limits>

using namespace std;


#define MAX(type) sizeof(numeric_limits<type>::max())
#define MIN(type) sizeof(numeric_limits<type>::min())

int main(void)
{
	cout << "type: min : max\n";
	cout << hex;
	cout << "bool:" << sizeof(numeric_limits<bool>::min()) << " " << sizeof(numeric_limits<bool>::max()) << endl;
	cout << "char:" << sizeof(numeric_limits<char>::min()) << " " << sizeof(numeric_limits<char>::max()) << endl;
	cout << "short:" << sizeof(numeric_limits<short>::min()) << " " << sizeof(numeric_limits<short>::max()) << endl;
	cout << "int:" << sizeof(numeric_limits<int>::min()) << " " << sizeof(numeric_limits<int>::max()) << endl;
	cout << "long:" << MIN(long) << ":" << MAX(long) << endl;
	cout << "long long:" << MIN(long long) << ":" << MAX(long long) << endl;
	cout << "float:" << MIN(float) << ":" << MAX(float) << endl;
	cout << "double:" << MIN(double) << ":" << MAX(double) << endl;
	cout << "long double:" << MIN(long double) << ":" << MAX(long double) << endl;
	cout << "unsigned:" << MIN(unsigned) << ":" << MAX(unsigned) << endl;
	cout << "unsigned long:" << MIN(unsigned long) << ":" << MAX(unsigned long) << endl;

	return 0;
}
