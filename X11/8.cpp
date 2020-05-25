#include <iostream>
#include <string>
#include <map>
#include <sstream>
#include <cassert>
#include <cstdlib>
#include <ctime>
#include <bits/stdc++.h> 


using namespace std;

int find_nth(int* array, size_t len, size_t find_index)
{
    cout << "find: " << find_index << endl;
    for (int i = 0; i < len; i++) {
        cout << array[i] << " ";
    }
    cout << endl;

    srand(time(nullptr));
    int pivot_index = rand() % len;
    int pivot = array[pivot_index];
    cout << "pivot=" << pivot << " " << pivot_index << endl;

    int* left_less_eq = new int[len];
    int left_index = 0;
    int* right_great = new int[len];
    int right_index = 0;
    int* pivots = new int[len];
    int pivots_index = 0;
    int ret;

    for (int i = 0; i < len; i++) {
        if (pivot > array[i]) {
            left_less_eq[left_index++] = array[i];
        } else if (pivot == array[i]) {
            pivots[pivots_index++] = array[i];
        } else {
            right_great[right_index++] = array[i];
        }
    }


    if (left_index > find_index) {
        ret = find_nth(left_less_eq, left_index, find_index);
    } else if (left_index + pivots_index > find_index) {
        ret = pivot;
    } else {
        ret = find_nth(right_great, right_index, find_index - left_index - pivots_index);
    }

    delete [] left_less_eq;
    delete [] right_great;

    return ret;
}

int main(void)
{
    int test1[] = {0,1,2,3,4,5,6,7};
    int test2[] = {5,4,7,3,5,2,4,6};
    int test3[] = {0,1};
    int ret;
    //cout << find_nth(test2, sizeof(test2) / sizeof(test2[0]), 1) << endl;
    ret = find_nth(test2, sizeof(test2) / sizeof(test2[0]), 6);
    sort(test2, test2 + sizeof(test2) / sizeof(test2[0]));
    for (int i = 0; i < sizeof(test2) / sizeof(test2[0]); i++) {
        cout << test2[i] << " ";
    }
    cout << endl;

    cout << ret << " == " << test2[6] << endl;

    return 0;
}