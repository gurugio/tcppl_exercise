#include <iostream>
#include <string>

using namespace std;


struct data {
	char ch[4];
	short sh;
	int num;
};
	
int main(void)
{
	struct data data = {"xyz", 1, 2};
	char* ptr_char = data.ch;
	short* ptr_short = &data.sh;

	cout << alignof(data.ch[1]) << endl; // 1

	//int *ptr = static_cast<int *>(&data.ch[1]); // compile error "invalid static_cast"

	
	
	return 0;
}
