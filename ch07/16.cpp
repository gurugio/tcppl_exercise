#include<iostream>

using namespace std;

void print(int value, int base = 10)
{
    char b[100];
    int len = 0;
    int i = value; //itoa만든거를 복사해온거라 변수 이름이 i임

    if (i == 0)
    {
        b[len++] = '0';
    }
    else
    {
        while (i > 0)
        {
            if (i % base >= 10)
            {
                b[len++] = 'a' + (char)((i % base) - 10);
            }
            else
            {
                b[len++] = '0' + (char)(i % base);
            }
            i /= base;
        }
    }

    b[len] = 0;

    // reverse string
    len--;
    for (int k = 0; k < len; k++, len--)
    {
        char t = b[k];
        b[k] = b[len];
        b[len] = t;
    }

    cout << b << endl;
}

int main(void)
{
    print(10, 10);
    print(10, 16);
    print(10, 8);

    print(31);
    print(31, 10);
    print(31, 16);
    print(31, 2);
    
}

