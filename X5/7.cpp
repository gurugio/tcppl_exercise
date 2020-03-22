#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


int main(void)
{
	vector<int> numbers {5, 9, -1, 200, 0};

	cout << "before:";
	for (auto a: numbers)
		cout << a << endl;

	sort(numbers.begin(), numbers.end());

	cout << "after:";
	for (auto a: numbers)
		cout << a << endl;
	
}
