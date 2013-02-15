#include <iostream>
#include <string>

using namespace std;



int main(void)
{
    char* pc;
    int arr_int[10] = {1, 2, 3, 4, 5,};
    int (&array_ref)[10] = arr_int;
    //int &array_ref[10] = arr_int; error: declaration of ‘array_ref’ as array of references

    cout << array_ref[2] << '\n';
    
    string* parr_str;
    string arr_str[10] = {
        string("asdf"),
        string("bbbb"),
    };

    parr_str = &arr_str[0];
    cout << *parr_str << '\n';
    parr_str++;
    cout << *parr_str << '\n';

    char **ppc;
    int int_data = 10;
    int another_int_data = 11;
    const int const_int = int_data;

    //1.cpp:33:17: error: assignment of read-only variable ‘const_int’
    //const_int = another_int_data;
    
    const int* pconst_int = &int_data;

    pconst_int = &another_int_data; // possible
    pconst_int++; // possible 이게 가능하므로 함수 인자를 const로 받아서 함수에서 포인터 연산을 할 수 있는 것임
    //(*pconst_int)++; // impossible

    int *const const_pint = &int_data;
    (*const_pint)++; // possible
    //const_pint = &another_int_data; // impossible
    
    return 0;
}
