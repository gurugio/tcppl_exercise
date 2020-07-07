#include <iostream>
#include <cstring>

using namespace std;


using fptr = void (*)(char*, int&);

void func_example(char* msg, int& count)
{
	cout << "message: " << msg << endl;
	cout << "count: " << count << endl;
	count++;
}

fptr ftoptr(fptr func, char* msg, int val)
{
	func(msg, val);
	return func;
}

int main(void)
{
	int v = 0;
	char *msg = new char[20];
	strcpy(msg, "asdf");
	fptr f = ftoptr(func_example, msg, v);
	f(msg, v);

	func_example(msg, v);
	func_example(msg, v);
	func_example(msg, v);
	
	return 0;
}
