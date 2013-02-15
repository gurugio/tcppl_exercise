#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <string.h>

using namespace std;


int count_pair_string(string& source_string, string& pair)
{
    size_t pos = 0;
    int count = 0;

    while (1)
    {
        pos = source_string.find(pair, pos);

        if (pos == string::npos)
            break;
        else
            count++;
        
        cout << "found at " << pos << '\n';

        pos++;
    }

    return count;
}

int count_pair_cstring(char* src, char* pair)
{
    int count = 0;
    char *orig = src;


    while (*src != 0)
    {
        if (strncmp(src, pair, 2) == 0)
        {
            count++;
            cout << "found at " << src - orig << '\n';
        }

        src++;
    }
        
    return count;
}



int main(void)
{
    string data = "xabaacbaxabbaxdbabfeabaabbbbaedadba";
    string target = "ab";
    
    count_pair_string(data, target);

    count_pair_cstring((char *)data.c_str(), (char *)target.c_str());

    return 0;
}
