#include <iostream>
#include <string>

using namespace std;

int main(void)
{
	char char_data = 'x';
	char* ptr_char = &char_data;;
	int array_int[10] = {0,1,2,3,4,5,6,7,8,9};
	int (&ref_array_int)[10] {array_int};
	string array_string[10] = {"0","1","2","3","4","5","6","7","8","9"};
	string *ptr_array_string {array_string};
	char** pp_char = &ptr_char;
	const int const_int = array_int[3];
	const int* ptr_const_int = &const_int;

	int* const const_ptr_int = &array_int[4];
	
	for (int i = 0; i < 10; i++) {
		cout << ref_array_int[i] << ";" << ptr_array_string[i] << endl;
	}
	cout << **pp_char << endl;
	cout << const_int << endl;

	//*ptr_const_int = 4; compile error

	*const_ptr_int = 555; // compile ok
	cout << array_int[4] << endl;
	
	return 0;
}
