#include <iostream>
#include <string>


using namespace std;


int main(void)
{
    char str[] = "a short string";

    cout << sizeof(str) << ":" << string(str).length() << '\n';
    
    return 0;
}
