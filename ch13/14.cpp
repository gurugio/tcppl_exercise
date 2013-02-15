#include <iostream>
#include <string>

using namespace std;



template<class C>
int compare(const string &str1, const string &str2)
{
    for (int i = 0; i < str1.length() && i < str2.length(); i++)
    {
        if (!C::eq(str1[i], str2[i]))
            return C::lt(str1[i], str2[i]) ? -1: 1;
    }
    return str1.length() - str2.length();
}


template<class T> class Cmp {
public:
    static int eq(T a, T b) { return a == b; }
    static int lt(T a, T b) { return a<b; }
};

class CmpCaseless {
public:
    static int eq(char a, char b)
    {
        a &= 0x2;
        b &= 0x2;
        return a == b;
    }
    static int lt(char a, char b)
    {
        a &= 0x2;
        b &= 0x2;
        return a < b;
    }
};

int main(void)
{
    string s1 = "abcd";
    string s2 = "bcde";
    
    cout << compare<Cmp<char> >(s1, s2) << endl;
    cout << compare<Cmp<char> >(s2, s1) << endl;
    cout << compare<Cmp<char> >(s2, s2) << endl;

    s1 = "AbCd";
    s2 = "aBcD";
    cout << compare<CmpCaseless >(s1, s2) << endl;
    cout << compare<CmpCaseless >(s2, s1) << endl;
    cout << compare<CmpCaseless >(s2, s2) << endl;

    s1 = "abcd";
    s2 = "BCDE";
    cout << compare<CmpCaseless >(s1, s2) << endl;
    cout << compare<CmpCaseless >(s2, s1) << endl;
    cout << compare<CmpCaseless >(s2, s2) << endl;
    
    
    
}
