#include <iostream>

using namespace std;

int global_array[] = {0,1,2,3,4,5,6,7,8,9};
					  
int main(void)
{
	int local_array[] = {0,11,22,33,44,55,66,77,88,99};
	int *alloc_array = new int[10];

	for (int i = 0; i < 10; i++)
		alloc_array[i] = i * 111;

	for (int i = 0; i < 10; i++)
		cout << global_array[i] << ":" << local_array[i] << ":" << alloc_array[i] << endl;

	// access around boundary
	// No optimization: prints random number without error
	// -O2: same
	cout << "access around boundary\n";
	for (int i = -10; i < 0; i++)
		cout << global_array[i] << ":" << local_array[i] << ":" << alloc_array[i] << endl;
	for (int i = 10; i < 20; i++)
		cout << global_array[i] << ":" << local_array[i] << ":" << alloc_array[i] << endl;

	// No optimization: prints random number without error
	// -O2: same
	cout << "access a little far from the boundary\n";
	for (int i = -110; i < -100; i++)
		cout << global_array[i] << ":" << local_array[i] << ":" << alloc_array[i] << endl;
	for (int i = 100; i < 110; i++)
		cout << global_array[i] << ":" << local_array[i] << ":" << alloc_array[i] << endl;

	// No optimization: prints some zeros and generate segfault
	// -O2: same
	cout << "access farther from the boundary\n";
	for (int i = 1000; i < 1100; i++)
		cout << global_array[i] << ":" << local_array[i] << ":" << alloc_array[i] << endl;

}
