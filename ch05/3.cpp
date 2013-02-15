#include <iostream>
#include <string>
#include <stdio.h>

using namespace std;

typedef unsigned char uc;
typedef const unsigned char cuc;
typedef int * pi;
typedef char * pc;
typedef char (*p_array_of_char)[3];
typedef int *p_array_of_int[7];
typedef p_array_of_int p_p_array_of_int7[8];

int main(void)
{
    char char_array[3] = {'a','b','c'};
    p_array_of_char paoc = &char_array;
    printf("%p == %p\n", &char_array[0], paoc);

    int int_array[7] = {1,2,3,4,5,6,7};
    p_array_of_int pint_array = {&int_array[0],
                                 &int_array[1],
                                 &int_array[2],
                                 &int_array[3],
                                 &int_array[4],
                                 &int_array[5],
                                 &int_array[6]};
    printf("%p == %p\n", &int_array[3], pint_array[3]);

    p_p_array_of_int7 ppint_array;
    ppint_array[0][0] = pint_array[0];
    ppint_array[0][1] = pint_array[1];
    ppint_array[0][2] = pint_array[2];
    ppint_array[0][3] = pint_array[3];
    ppint_array[0][4] = pint_array[4];
    ppint_array[0][5] = pint_array[5];
    ppint_array[0][6] = pint_array[6];
    
    ppint_array[2][0] = pint_array[0];
    ppint_array[2][1] = pint_array[1];
    ppint_array[2][2] = pint_array[2];
    ppint_array[2][3] = pint_array[3];
    ppint_array[2][4] = pint_array[4];
    ppint_array[2][5] = pint_array[5];
    ppint_array[2][6] = pint_array[6];

    cout << sizeof(ppint_array) << " == " << 7*8*sizeof(int *) <<'\n';

    
    return 0;
}
