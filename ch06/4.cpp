#include <iostream>
#include <map>
#include <iterator>

using namespace std;


int or_table[2][2] = {
    {0, 1},
    {1, 1}
};

int and_table[2][2] = {
    {0, 0},
    {0, 1}
};

int main(void)
{
    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            cout << i << " | " << j << " = " << or_table[i][j] << endl;
            cout << i << " & " << j << " = " << and_table[i][j] << endl;
        }
    }

    return 0;
}
