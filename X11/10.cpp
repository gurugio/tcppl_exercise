#include <iostream>
#include <string>
#include <map>
#include <sstream>
#include <cassert>
#include <cstdlib>
#include <ctime>
#include <bits/stdc++.h> 


using namespace std;

void rev(char* src)
{
    int l = strlen(src);
    for (int i = 0; i < l / 2; i++) {
        char t = src[i];
        src[i] = src[l - i - 1];
        src[l - i - 1] = t;
    }
}

int main(void)
{
    char ddd[10];

    strcpy(ddd, "a");
    rev(ddd);
    cout << ddd << endl;

    strcpy(ddd, "ab");
    rev(ddd);
    cout << ddd << endl;

    strcpy(ddd, "abc");
    rev(ddd);
    cout << ddd << endl;

    strcpy(ddd, "abcd");
    rev(ddd);
    cout << ddd << endl;

    strcpy(ddd, "abcde");
    rev(ddd);
    cout << ddd << endl;

    return 0;
}