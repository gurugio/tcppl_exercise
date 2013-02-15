#include <iostream>

using namespace std;

int main(void)
{
    int i;
    int max_length = 30;
    char input_line[] = "?asdf?asdf?zxcv?as";
    int quest_count = 0;
    
    for (i = 0; i < max_length; i++)
    {
        if (input_line[i] == '?')
            quest_count++;
    }

    cout << quest_count << endl;

    while (input_line[i++] != 0)
    {
        if (input_line[i] == '?')
            quest_count++;
    }

    cout << quest_count << endl;

    return 0;
}
