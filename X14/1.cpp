#include <iostream>
#include <cstring>

using namespace std;

#if 0
// 1st implementation
template<typename T>
class Checked_ptr {
	T* start_addr;
	size_t array_size;

public:
	Checked_ptr(T* p, size_t s) : start_addr{p}, array_size{s}
	{
		if (start_addr == nullptr) throw runtime_error{"Checked_ptr: null"};
	}

	T operator[](int i)
	{
		if (i >= array_size || i < 0 || array_size <= 0)
			throw runtime_error{"Checked_ptr: beyond limit"};
		return start_addr[i];
	}

	void operator++(int)
	{
		start_addr++;
		array_size--;
		cout << "array_size:" << array_size << endl;
	}
	
	T operator*()
	{
		if (array_size <= 0)
			throw runtime_error{"Checked_ptr: beyond limit"};
		return *start_addr;
	}
};
#endif

template<typename T>
class Checked_ptr {
	T* start_addr;
	T* end_addr; // pointer to the last element

public:
	Checked_ptr(T* p, size_t s) : start_addr{p}, end_addr{&p[s - 1]}
	{
		if (start_addr == nullptr) throw runtime_error{"Checked_ptr: null"};
	}

	T operator[](int i)
	{
		if (&start_addr[i] > end_addr)
			throw runtime_error{"Checked_ptr: beyond limit by []"};
		return start_addr[i];
	}

	void operator++(int)
	{
		start_addr++;
		if (start_addr > end_addr)
			throw runtime_error{"Checked_ptr: beyond limit by ++"};
	}
	
	T operator*()
	{
		if (start_addr > end_addr)
			throw runtime_error{"Checked_ptr: beyond limit by *"};
		return *start_addr;
	}
};

int main(void)
{
	int array[10] = {0,1,2,3,4,5,6,7,8,9};
	Checked_ptr<int> checked_pint{array, 10};

	try {
		cout << checked_pint[9] << endl;
		cout << checked_pint[10] << endl;  // error
	} catch (exception& e) {
		cerr << e.what() << endl;
	}

	char message[] = "i am good";
	Checked_ptr<char> checked_pchar{message, strlen(message)};

	try {
		cout << checked_pchar[strlen(message) - 1] << endl;
		cout << checked_pchar[strlen(message)] << endl; // error
	} catch (exception& e) {
		cerr << e.what() << endl;
	}

	try {
		for (int i = 0; i < 10; i++) {
			cout << *checked_pint << endl;
			checked_pint++;
		}
		cout << *checked_pint << endl; // error
	} catch (exception& e) {
		cerr << e.what() << endl;
	}

}
