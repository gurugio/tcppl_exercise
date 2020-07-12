#include <iostream>
#include <vector>

using namespace std;


#define ABC "abc"
#define PI 3.14

vector<int> vec;

int main(void)
{
	cout << ABC << endl;
	cout << PI << endl;
	vec.push_back(PI);
	for (auto x: vec)
		cout << x << endl;
}
