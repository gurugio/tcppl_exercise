#include <iostream>
#include <cstring>

using namespace std;

char* cat(char* p, const char* q)
{
    int new_size = strlen(p) + strlen(q) + 1;
    char *buf = new char[new_size];
    char *prev = buf;

    cout << new_size << endl;
    
    while (*buf = *p)
        buf++,p++;

    while (*buf = *q)
        buf++, q++;

    return prev;
}


int main(void)
{
    char a[64] = "1234567890123456";
    char b[64] = "12345678";

    cout << cat(a, b) << endl;
    cout << cat(b, a) << endl;
        
}
