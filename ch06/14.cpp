#include <iostream>
#include <cstring>

using namespace std;


char *rev(char *buf)
{
    int end = strlen(buf) - 1;
    int start = 0;

    while (start <= end)
    {
        char t = buf[start];

        buf[start] = buf[end];
        buf[end] = t;

        start++, end--;
    }

    return buf;
}

int main(void)
{
    char a[64] = "1234567890123456";
    char b[64] = "12345678";

    cout << rev(a) << endl;
    cout << rev(b) << endl;
}

