#include <iostream>

using namespace std;


int main(void)
{
	int data[] = {0,1,2,3,4,5,6,7,8,9};
	int *p1 = &data[3];
	int *p2 = &data[6];

	cout << p2 - p1 << endl;
}
