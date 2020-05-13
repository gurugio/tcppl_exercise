#include <iostream>

using namespace std;

int main(void)
{
	char char_c = 255;
	unsigned char unsigned_c = 255;
	signed char signed_c = 255;
	int ctoi {char_c};

	cout << "only char: " << ctoi << endl;
	cout << "unsigned char: " << int{unsigned_c} << endl;
	cout << "signed char: " << int{signed_c} << endl;

	if (int{signed_c} == ctoi)
		cout << "signed\n";
	else
		cout << "unsigned\n";
	
	return 0;
}
