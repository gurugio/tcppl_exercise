#include <iostream>

using namespace std;


char *my_itoa(int i, char b[])
{
    int len = 0;

    if (i == 0)
    {
        b[len++] = '0';
    }
    else
    {
        while (i > 0)
        {
            b[len++] = '0' + (char)(i % 10);
            i /= 10;
        }
    }

    b[len] = 0;

    len--;
    for (int k = 0; k < len; k++, len--)
    {
        char t = b[k];
        b[k] = b[len];
        b[len] = t;
    }
    
    return b;
}

int main(void)
{
    char buf[124];
    
    cout << my_itoa(12034, buf) << endl;
    cout << my_itoa(10, buf) << endl;
    cout << my_itoa(1, buf) << endl;
    cout << my_itoa(0, buf) << endl;
    
}

