#include <iostream>

using namespace std;

int main(void)
{
	// implementation-defined:
	// 1. the number of bits in char
	cout << sizeof(char)*8 << endl;
	// 2. the number of bits in pointer
	cout << sizeof(int *) * 8 << endl;
	// 3. identifier characters
	//int 변수 = 1; -> compile error
	// 4. source file inclusion
	// 5. The mapping of physical source file multi-byte characters to the execution character set
	
	// undefined:
	// 1. return value of new of size zero
	int *new_error = new int[0];
	cout << hex << new_error << dec << endl;

	// 2. shared variable by two threads without synchronization
	// 3. dereferencing a pointer out of boundary
	*(new_error + 1) = 1;
	// 4. dereferencing null pointer
	new_error = nullptr;
	*new_error = 1;
	
	// 5. dereferencing a uninitialized pointer
	int *uninit_ptr;
	*uninit_ptr = 1;

}
