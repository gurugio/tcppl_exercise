#include <iostream>

using namespace std;


enum class EnumName{ Value1, Value2, ValueN};

int main(void)
{
	cout << "data types\n";
	cout << sizeof(char) << endl;
	cout << sizeof(short) << endl;
	cout << sizeof(int) << endl;
	cout << sizeof(long) << endl;
	cout << sizeof(long long) << endl;
	cout << sizeof(long int) << endl;
	cout << sizeof(float) << endl;
	cout << sizeof(double) << endl;

	cout << "pointers\n";
	cout << sizeof(char *) << endl;
	cout << sizeof(short *) << endl;
	cout << sizeof(int *) << endl;
	cout << sizeof(long *) << endl;
	cout << sizeof(long long *) << endl;
	cout << sizeof(long int *) << endl;
	cout << sizeof(float *) << endl;
	cout << sizeof(double *) << endl;

	cout << "enum class\n";
	cout << sizeof(EnumName) << endl;
	cout << sizeof(EnumName::Value1) << endl;
}
