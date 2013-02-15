#include <iostream>
#include <stdio.h>

using namespace std;


int day_per_month[] = {
    0,
    31, 28, 31, 30, 31, 30,
    31, 31, 30, 31, 30, 31};

int day_per_month_leap[] = {
    0,
    31, 29, 31, 30, 31, 30,
    31, 31, 30, 31, 30, 31};

    

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

void add_day(struct Date &date)
{
    if (0 != (date.yyyy % 4))
    {
        if (date.dd >= day_per_month[date.mm])
        {
            date.dd = 1;
            date.mm++;
        }
        else
        {
            date.dd++;
        }
    }
    else
    {
        if (date.dd >= day_per_month_leap[date.mm])
        {
            date.dd = 1;
            date.mm++;
        }
        else
        {
            date.dd++;
        }
    }

    
    if (date.mm > 12)
    {
        date.yyyy++;
        date.mm = 1;
    }
}



int main(void)
{
    struct Date today = {2012,6,19};

    print_date(today);

    // 좀 이상한 방법이지만 레퍼런스를 이렇게도 되나 해봤나. 잘되네.
    struct Date& tomo = make_date(2012,6,20);

    print_date(tomo);

    today.yyyy = 2011;
    today.mm = 12;
    today.dd = 29;

    for (int i = 0; i < 100; i++)
    {
        print_date(today);
        add_day(today);
    }
    
    today.yyyy = 2012;
    today.mm = 12;
    today.dd = 29;

    for (int i = 0; i < 100; i++)
    {
        print_date(today);
        add_day(today);
    }
    
    return 0;
}
