#include <iostream>

using namespace std;

void print(int);
void print(const char*);
void print(double);
void print(long);
void print(char);


void print(int n)
{
	printf("%d\n", n);
}

void print(const char* str)
{
	printf("%s\n", str);
}

void print(double d)
{
	printf("%lf\n", d);
}

void print(long ld)
{
	printf("%ld\n", ld);
}

void print(char c)
{
	printf("%c\n", c);
}

int main(void)
{
	print(3);
	print("asdf");
	print(3.14);
	print(0x1234567890abcd);
	print('x');
}
