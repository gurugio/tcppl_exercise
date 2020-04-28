#include <iostream>
#include <cstring>

using namespace std;

int main(void)
{
	char str[] = "a short string";
	cout << sizeof(str) << endl; // 15
	cout << strlen(str) << endl; // 14
}
