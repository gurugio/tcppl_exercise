#include <iostream>
#include <stdio.h>

using namespace std;


struct pp
{
    int m;
};

int main(void)
{
    struct pp ddd[3];
    struct pp* p = ddd;

    ddd[0].m = 0;
    ddd[1].m = 11;
    ddd[2].m = 22;

    *(p++);
    cout << p->m << endl;    

    *(--p);
    cout << p->m << endl;    

    int a = 3;
    (++a)--;
    cout << a << endl;

    cout << (int*)(p->m) << endl;

    cout << (*p).m << endl;

    int* b[3] = {&(ddd[0].m), &(ddd[1].m), &(ddd[2].m)};
    int i = 1;
    
    cout << *(b[i]) << endl;

    int** c = &b[0];
    cout << (*c)[i] << endl;


    char str[4] = "abc";
    char *pa = &str;
    char *pb = &str[0];

    printf("%p %p %p\n", str, pa, pb);
    printf("%p %p\n", ++pa, ++pb);
}
