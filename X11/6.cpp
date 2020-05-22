#include <iostream>

using namespace std;

struct ppp {
    int *m;
    int *n;
};

int main(void)
{
    int arr[5] = {0,11,22,33,44};
    int *p = &arr[2];

    int arr2[5] = {0,11,22,33,44};
    int *q = &arr2[2];

    // *p++ -> *p and p++
    cout << *p++ << " = " << *(q++) << endl; // arr[2]
    cout << *p << endl; // arr[3]
    // *--p -> --p and *p
    cout << *--p << " = " << *(--q) << endl; // arr[2]
    cout << *p << endl; // arr[2]

    // int a = 123;
    // cout << ++a-- << endl;
/*     gkim@gkim-laptop:~/tcppl_exercise/X11$ g++ 6.cpp && ./a.out
    6.cpp: In function ‘int main()’:
    6.cpp:21:16: error: lvalue required as increment operand
    21 |     cout << ++a-- << endl;
      |  
 */    

    struct ppp pdata {&arr[1], &arr[2]};
    struct ppp *ptr = &pdata;

    cout << (int*)ptr->m << endl;
    cout << (int*)(ptr->m) << endl;

    cout << (*ptr).m << endl;
    
    int *a[2] {&arr[0], &arr[1]};
    cout << *a[1] << "=" << *(a[1]) << endl;
}
/* ∗p++
∗−−p
++a−−
(int∗)p−>m
∗p.m
∗a[i] */