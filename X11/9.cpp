#include <iostream>
#include <string>
#include <map>
#include <sstream>
#include <cassert>
#include <cstdlib>
#include <ctime>
#include <bits/stdc++.h> 


using namespace std;


char* my_cat(const char* src1, const char* src2)
{
    size_t l1 = strlen(src1);
    size_t l2 = strlen(src2);
    char* dst = new char[l1 + l2 + 1];
    
    strcpy(dst, src1);
    strcpy(dst + l1, src2);
    dst[l1 + l2] = '\0';
    return dst;
}

int main(void)
{
    cout << my_cat("this is ", "sparta!") << endl;
    cout << my_cat("I am a ", "boy...") << endl;
    cout << my_cat("", "How are you?") << endl;
    return 0;
}