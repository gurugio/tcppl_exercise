#include <iostream>
#include <cstdarg>
#include <cstring>
using namespace std;


void error(string format, ...)
{
	va_list ap;
	va_start(ap, format);

	for (unsigned int i = 0; i < format.length(); i++) {
		if (format[i] == '%') {
			if (format[i + 1] == 'c') {
				i++;
				char ch = va_arg(ap, int);
				cout << ch;
			} else if (format[i + 1] == 's') {
				i++;
				char* ptr = va_arg(ap, char*);
				cout << ptr;
			} else if (format[i + 1] == 'd') {
				i++;
				int num = va_arg(ap, int);
				cout << num;
			} else {
				cout << format[i];
			}
		} else {
			cout << format[i];
		}
	}
	
	va_end(ap);
	
}

int main(void)
{
	char ch = 'x';
	int num = 123456;
	char cstr[20];
	strcpy(cstr, "hello!"); //  char* cstr = "hello!" generates a warning
	error("print %c %d %s\n", ch, num, cstr);
}
