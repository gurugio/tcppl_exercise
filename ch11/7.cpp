#include <iostream>
#include <string>

using namespace std;

class String_iter {
    string &rf_str;
    int index;
public:
    String_iter(string &s);
    char &next();

};

String_iter::String_iter(string &s) : rf_str(s)
{
    index = 0;
}

char &String_iter::next(void)
{
    return rf_str[index++];
}

int main(void)
{
    string str = "i am a boy";
    String_iter str_iter(str);

    while (char c = str_iter.next())
        cout << c << endl;

}
