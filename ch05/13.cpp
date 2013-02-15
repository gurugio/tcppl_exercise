#include <iostream>
#include <stdio.h>

using namespace std;



struct Date {
    int yyyy;
    int mm;
    int dd;
};


void print_date(struct Date& d)
{
    cout << "This is " << d.yyyy << ":" << d.mm << ":" << d.dd << '\n';
}


struct Date& make_date(int y, int m, int d)
{
    struct Date *ddd = new struct Date;

    printf("%p\n", ddd);

    ddd->yyyy = y;
    ddd->mm = m;
    ddd->dd = d;
    
    return (*ddd);
}


int main(void)
{
    struct Date today = {2012,6,19};

    print_date(today);

    // 좀 이상한 방법이지만 레퍼런스를 이렇게도 되나 해봤나. 잘되네.
    struct Date& tomo = make_date(2012,6,20);

    print_date(tomo);

    printf("%p\n", &tomo);
    
    return 0;
}
