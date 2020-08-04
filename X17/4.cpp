#include <iostream>
#include <climits>
#include <map>

using namespace std;

class Out_of_range {
public:
	Out_of_range(int n): val{n} {}
	int val;
};
	
class Histogram {
public:
	explicit Histogram(int min =0, int max =INT_MAX);

	void count(int n);
	void print(void) const;
private:
	map<int, int> table;
	int min, max;
};

Histogram::Histogram(int min, int max)
{
	this->min = min;
	this->max = max;
}

void Histogram::count(int n)
{
	if (min > n || max < n)
		throw Out_of_range(n);
	
	map<int, int>::iterator it;
	it = table.find(n);
	if (it != table.end()) {
		table[n]++;
	} else {
		table[n] = 1;
	}
}

void Histogram::print(void) const
{
	// This is not printing the histogram though
	for (auto it: table) {
		cout << it.first << ":" << it.second << endl;
	}
}

int main(void)
{
	Histogram hist {0, 100};
	try {
		hist.count(1);
		hist.count(2);
		hist.count(2);
		hist.count(2);
		hist.count(2);
		hist.count(101);
	} catch (Out_of_range& e) {
		cout << "out-of-range:" << e.val << endl;
	}
	hist.print();

}
