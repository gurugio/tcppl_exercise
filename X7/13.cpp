#include <iostream>
#include <map>

using namespace std;


int main(void)
{
	map<int, int> data;
	data[0] = 4;
	data[1] = 5;
	data[2] = 9;
	data[3] = 17;
	data[4] = 12;

	for (pair<int, int> p: data)
		cout << p.second << endl;

	return 0;
}
