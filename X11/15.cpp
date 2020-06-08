#include <iostream>
#include <vector>

using namespace std;

int main(void)
{
    int arr_int[] = {1,2,3,4,0,0,4,5,6,7,0,2,3,5,0,0};
    vector<int> vec_int;
    int arr_len = sizeof(arr_int) / sizeof(arr_int[0]);

    for (int *ptr = &arr_int[0]; ptr < &arr_int[arr_len]; ptr++) {
        if (*ptr) vec_int.push_back(*ptr);
    }

    for (auto x: vec_int) {
        cout << x << endl;
    }

    return 0;
}