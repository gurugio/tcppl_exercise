#include <iostream>
#include <vector>
#include <algorithm>
#include <set>


using namespace std;

class Accumulator
{
public:
	Accumulator(int x) : sum(x) {}
	Accumulator() : sum(0) {}
	void operator()(int x) {
		sum += x;
	}
	int operator()() {
		return sum;
	}
private:
	int sum;
};


template<typename TN>
typename TN::value_type summation(TN& container, typename TN::value_type base)
{
	for (auto x: container)
		base += x;
	return base;
}

int main(void)
{
	vector<int> array {1,2,3,4,5,6,7,8,9,10};
	int sum = 0;

	// 1. for-loop & index
	for (int i = 0; i < array.size(); i++)
		sum += array[i];
	cout << "for-loop and index:" << sum << endl;
	sum = 0;
	
	// 2. for-loop & pointers
	int *p = &array[0];

	for (int *p = &array[0]; p < &array[array.size()]; p++) {
		sum += (*p);
	}
	cout << "for-loop and pointer:" << sum << endl;
	sum = 0;

	// 3. iterator
	vector<int>::iterator iter;
	for (iter = array.begin(); iter != array.end(); iter++) {
		sum += *iter;
	}
	cout << "iterator: " << sum << endl;
	sum = 0;
	
	// 4. range-for
	for (const auto& a: array)
		sum += a;
	cout << "range-for: " << sum << endl;
	sum = 0;

	// 5. for-each
	for_each(array.begin(), array.end(), [&sum](const int& x) { sum += x; });
	cout << "for-each: " << sum << endl;
	sum = 0;

	// 6. range-for and functor
	Accumulator accum {};
	for (const auto& a: array)
		accum(a);
	cout << "functor: " << accum() << endl;

	// 7. template for various data types
	vector<int> array_int {1,2,3,4,5,6,7,8,9,10};
	cout << "int-vector:" << summation(array_int, 0) << endl;
	vector<double> array_double {1.1,2.0,3.0,4.0,5.0};
	cout << "double-vector:" << summation(array_double, 40) << endl;
	set<int> set_int {1,2,3,4,5};
	cout << "int-set:" << summation(set_int, 40) << endl;
	
	return 0;
}
