#include <iostream>
#include <chrono>

using namespace std;
using namespace chrono;


int aligned_16 __attribute__ ((aligned (16))) = 0;

struct foo
{
	char a;
	int x[2] __attribute__ ((packed));
};

struct bar
{
	char a;
	int x[2];
};

void clean(int *final_value)
{
	cout << "clean: " << *final_value << endl;
}

int main(void)
{
	int x = 1;

	//
	// gcc built-in functions
	//
	
	cout << __builtin_abs(-4) << endl;

	if (__builtin_expect(x, 1)) // return value is x
		cout << "x is expected as 1\n";

	int *a = new int[1024*1024*100];
	int *b = new int[1024*1024*100];
	high_resolution_clock::time_point before = high_resolution_clock::now();
	for (int i = 0; i < 1024*1024; i++) {
		a[i] = a[i] + b[i];
	}
	high_resolution_clock::time_point after = high_resolution_clock::now();
	duration<double> time_span = duration_cast<duration<double>>(after - before);
	std::cout << time_span.count() << " seconds.\n";

	int *c = new int[1024*1024*100];
	int *d = new int[1024*1024*100];
	before = high_resolution_clock::now();
	for (int i = 0; i < 1024*1024; i++) {
		c[i] = c[i] + d[i];
		if (i % 64 == 0) {
			__builtin_prefetch (&c[i*64], 1, 1);
			__builtin_prefetch (&d[i*64], 0, 1);
		}
	}
	after = high_resolution_clock::now();
	time_span = duration_cast<duration<double>>(after - before);
	std::cout << time_span.count() << " seconds.\n";

	for (int i = 1; i < 0xffff; i *= 2)
		cout << __builtin_ffs(i) << endl;

	uint64_t swap = 0x12345678aabbccdd;
	cout << hex << __builtin_bswap64(swap) << dec << endl;

	// attributes of variables
	cout << hex << &aligned_16 << dec << endl;
	cout << sizeof(struct foo) << "!=" << sizeof(struct bar) << endl;

	{
		int dd __attribute__ (( __cleanup__ (clean))) = 1234;
	}
	
}
