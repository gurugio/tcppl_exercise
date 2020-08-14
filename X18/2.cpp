#include <iostream>

using namespace std;


template <typename T>
class spointer {
public:
	spointer(T* p): ptr{p} {
		cout << "this=" << this << " construction with " << ptr << endl;
	}
	spointer(): ptr{nullptr} {
		cout << "this=" << this << " construction with " << ptr << endl;
	}

	~spointer() {
		cout << "this=" << this << " destruction: " << ptr << endl;
		delete ptr;
	}

	/* copy operation to copy pointer to object
	spointer& operator=(T* p) {
		ptr = p;
		return *this;
	}
	*/

	T* ptr;
};

int main(void)
{
	int* arr = new int[20];
	cout << "arr=" << arr << endl;

	spointer<int> sp_int;

	/* Without copy-assignment, this generates double-free */
	/*
gkim@gkim-laptop:~/tcppl_exercise/X18$ g++ 2.cpp && ./a.out
arr=0x558877c37eb0
this=0x7ffe42a90620 construction with 0
this=0x7ffe42a90628 construction with 0x558877c37eb0
this=0x7ffe42a90628 destruction: 0x558877c37eb0
this=0x7ffe42a90620 destruction: 0x558877c37eb0
free(): double free detected in tcache 2
Aborted (core dumped)
gkim@gkim-laptop:~/tcppl_exercise/X18$ 
*/
	/* 1. make a rvalue object with arr
	 * 2. copy the rvalue object to sp_int
	 * 3. destruct the rvalue object -> delete ptr
	 * 4. destructor of sp_int calls 'delete ptr' again -> double-free!!
	 */
	sp_int = arr;
}
