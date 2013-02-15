#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main(void)
{
    vector<string> word_set;
    
    while (1)
    {
        string word;
        cout << "write a word:";
        cin >> word;

        if (word == string("Quit"))
            break;
        else
            word_set.push_back(word);
    }

    sort(word_set.begin(), word_set.end());
    
    for (vector<string>::const_iterator p = word_set.begin();
         p != word_set.end();
         ++p)
    {
        cout << *p << '\n';
    }
    
    return 0;
}
