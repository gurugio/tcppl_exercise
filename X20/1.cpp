#include <iostream>

using namespace std;

template<typename T>
class Ptr {
	T* ptr;
	T* array;
	int sz;

public:
	template<int N>
	Ptr(T* p, T(&a)[N]): ptr{p}, array{a}, sz{N} {
		cout << "init-array:" << ptr << ":" << array << ":" << sz << endl;
	}

	Ptr(T* p, T* a, int s): ptr{p}, array{a}, sz{s} {}
	Ptr(T* p): ptr{p}, array{p}, sz{1} {}

	Ptr& operator++() {
		if (array + sz <= ptr)
			throw runtime_error{"cannot access memory by pre++"};
		++ptr;
		return *this;
	}
	Ptr& operator--() {
		if (ptr == array)
			throw runtime_error{"cannot access memory by pre--"};
		--ptr;
		return *this;
	}
	
	Ptr operator++(int) {
		if (array + sz <= ptr)
			throw runtime_error{"cannot access memory by ++post"};
		Ptr<T> old {ptr, array, sz};
		++ptr;
		return old;
	}
	Ptr operator--(int) {
		if (array == ptr)
			throw runtime_error{"cannot access memory by --post"};
		Ptr<T> old {ptr, array, sz};
		--ptr;
		return old;
	}

	T& operator*() {
		if (array + sz <= ptr || array > ptr)
			throw runtime_error{"cannot access memory by *"};
		return *ptr;
	}

	T* operator->() {
		if (array + sz <= ptr || array > ptr)
			throw runtime_error{"cannot access memory by *"};
		return ptr;
	}
};


struct client {
	string name;
	int num;
};

int main(void)
{
	client cli[5] = {{"aaa", 111},
					 {"bbb", 222},
					 {"ccc", 333},
					 {"ddd", 444},
					 {"eee", 555}};
	Ptr<client> ppp{cli, cli};


	cout << (*ppp).name << endl;

	cout << (++ppp)->name << endl;
	cout << (++ppp)->name << endl;
	cout << (++ppp)->name << endl;
	cout << (++ppp)->name << endl;
	cout << (++ppp)->name << endl; // runtime-error
	
}
