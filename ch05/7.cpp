#include <iostream>

using namespace std;


char* month_arr[12] = {"jan",
                       "feb",
                       "march",
                       "apr",
                       "may",
                       "jun",
                       "jul",
                       "aug",
                       "sep",
                       "oct",
                       "nov",
                       "dec"};
int day_per_month[12] = {30,
                       31,
                       32,
                       33,
                       34,
                       35,
                       36,
                       37,
                       38,
                       39,
                       30,
                       31}; // i don't care


struct month_and_day
{
    char *month_name;
    int day;
};

struct month_and_day mad[12] = {
    {"jan", 31},
    {"feb", 30},
    {"mar", 30},
    {"apr", 30},
    {"may", 30},
    {"jun", 30},
    {"jul", 30},
    {"aug", 30},
    {"sep", 30},
    {"oct", 30},
    {"nov", 30},
    {"dec", 30}
};

int main(void)
{
    for (int i = 0; i < 12; i++)
    {
        cout << month_arr[i] << " has " << day_per_month[i] << " days\n";
    }

    for (int i = 0; i < 12; i++)
    {
        cout << mad[i].month_name << " has " << mad[i].day << " days\n";
    }
    
    return 0;
}
