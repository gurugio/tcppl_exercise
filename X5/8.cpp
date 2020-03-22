#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


int main(void)
{
	vector<string> names {"Kant", "Plato", "Aristotle", "Kierkegard", "Hume"};

	cout << "before:";
	for (auto a: names)
		cout << a << endl;

	sort(names.begin(), names.end());

	cout << "after:";
	for (auto a: names)
		cout << a << endl;
	
}
