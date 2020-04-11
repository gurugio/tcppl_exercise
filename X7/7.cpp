#include <iostream>
#include <limits>

using namespace std;

int main(void)
{
	for (char ch = 1; ch < numeric_limits<char>::max(); ch++) {
		cout.width(3);
		cout << int{ch};
		cout << ":";
		cout << hex << int{ch} << dec;
		cout << ":";
		cout << ch << endl;
	}
}
