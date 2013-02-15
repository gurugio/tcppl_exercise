#include <iostream>


using namespace std;




int main(void)
{

//     int a = 100/0; -> comile warning and floating point exception
// ~/caoskernel/trunk/tcpppl_exercise/ch06 $ g++ 8.cpp -Wall
// 8.cpp: In function ‘int main()’:
// 8.cpp:12:17: warning: division by zero [-Wdiv-by-zero]
// 8.cpp:12:9: warning: unused variable ‘a’ [-Wunused-variable]
// ~/caoskernel/trunk/tcpppl_exercise/ch06 $ ./a.out
// floating point exception (core dumped)

    int a = -1;

    a++; // -> 0
    cout << a << endl;

    a--; // -> -1
    cout << a << endl;

    unsigned int b = -1;

    b++; // -> 0
    cout << b << endl;

    b--; // -> 4294967295
    cout << b << endl;
    
    return 0;
}
