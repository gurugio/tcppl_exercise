#include <iostream>
#include <algorithm>

using namespace std;

struct Count {
	Count(int n): size{n} {}
	int size;
};

template <typename T>
class Vector {
public:
	Vector(initializer_list<T> lst) {
		int i = 0;
		size = lst.size();
		elem = new T[size];
		for (auto x: lst)
			elem[i++] = x;
		cout << "Init-list: size=" << size << " alloc=" << elem << endl;
	}
	
	Vector(Count c) {
		size = static_cast<int>(c.size);
		elem = new T[size];
		cout << "Init-Count: size=" << size << " alloc=" << elem << endl;
	}

	void print(void) {
		for (int i = 0; i < size; i++)
			cout << elem[i] << endl;
	}
private:
	int size;
	T* elem;
};


int main(void)
{
	Vector<int> ddd {{1,2,3,4}};
	ddd.print();

	// cannot use integer: confusing
	// 4.cpp:27:28: error: invalid static_cast from type ‘Count’ to type ‘int’
	//Vector<int> xxx {4};

	// always use Count type to initialize
	Vector<int> xxx {Count{4}};
	xxx.print();
}
