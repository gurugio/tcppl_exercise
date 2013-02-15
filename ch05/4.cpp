#include <iostream>
#include <string>
#include <stdio.h>

using namespace std;


void pint_swap(int *a, int *b)
{
    int t = *a;
    *a = *b;
    *b = t;
}

void rint_swap(int& a, int& b)
{
    int t = a;
    a = b;
    b = t;
}

int main(void)
{
    int origa = 10;
    int origb = 11;

    pint_swap(&origa, &origb);
    cout << origa << origb << '\n';
    rint_swap(origa, origb);
    cout << origa << origb << '\n';
    
    
    return 0;
}
