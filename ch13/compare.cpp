#include <iostream>

using namespace std;


template <typename T>
int compare(const T &v1, const T &v2)
{
    if (v1 < v2) return -1;
    if (v1 > v2) return 1;
    return 0;
}


int main(void)
{

    cout << compare(1, 0) << endl;

    string s1 = "hi", s2 = "world";
    cout << compare(s1, s2) << endl;


    cout << compare<char *>("b", "a") << endl;
    return 0;
}
