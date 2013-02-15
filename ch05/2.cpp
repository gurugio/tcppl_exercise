#include <iostream>
#include <string>

using namespace std;



int main(void)
{
    char* pc;
    int *pi;
    void *pv;

    pc = (char *)main;
    pi = (int *)(pc + 1);
    pv = (void *)main;

    cout << hex << (unsigned long)pc << ":" << pi << ":" << pv << '\n';

    cout << *pi << '\n';

    
    return 0;
}
