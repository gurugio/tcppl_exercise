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


void print_month(char *months[])
{
    for (int i = 0; i < 12; i++)
    {
        cout << months[i] << '\n';
    }
}

int main(void)
{
    for (int i = 0; i < 12; i++)
    {
        cout << month_arr[i] << '\n';
    }

    print_month(month_arr);
    
    return 0;
}
