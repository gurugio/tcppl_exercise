#include <iostream>
#include <cstring>


using namespace std;


size_t my_strlen(const char* p)
{
    const char* q = p;
    while (*q != 0)
        q++;
    return q - p;
}


        
char* my_strcpy(char* p, const char* q)
{
    while (*p = *q)
        p++,q++;

    return p;
}

int my_strcmp(const char* p, const char* q)
{
    if (p == q) return 0;
    
    while ((*p - *q) == 0)
        p++, q++;
    return *p - *q;
}


int main(void)
{
    char a[64] = "1234567890123456";
    char b[64] = "12345678";
    char c[100];

    cout << my_strlen(a) << ":" << my_strlen(b) << "=" << strlen(a) << ":" << strlen(b) <<  endl;

    my_strcpy(c, a);
    cout << a << endl;
    my_strcpy(c, b);
    cout << b << endl;

    cout << my_strcmp(a, b) << endl;
    cout << my_strcmp(b, a) << endl;
    cout << my_strcmp(a, a) << endl;
    cout << my_strcmp(b, b) << endl;
        
}
