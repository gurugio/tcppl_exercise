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
/*     cout << "find: " << find_index << endl;
    for (int i = 0; i < len; i++) {
        cout << array[i] << " ";
    }
    cout << endl;
 */
    srand(time(nullptr));
    int pivot_index = rand() % len;
    int pivot = array[pivot_index];
/*     cout << "pivot=" << pivot << " " << pivot_index << endl;
 */
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

// map: key= name
// valie = (sum, count)
map<string, pair<double, int> > name_table;

bool get_name(istream &is)
{
    string name1;
    string name2;
    double value;
    char sp;

    is.get(sp);
    if (isspace(sp) || sp == '\n') {
        cout << "end input\n";
        return false;
    } else {
        is.putback(sp);
    }

    is >> name1;

    is.get(sp);
    if (!isspace(sp)) {
        cout << "space expected\n";
        return false;
    }

    is >> name2;
    name1 += ' ';
    name1 += name2;

    is.get(sp);
    if (!isspace(sp)) {
        cout << "second space expected\n";
        return false;
    }

    is >> value;
    
    cout << name1 << ':' << value << endl;
    if (name_table.find(name1) == name_table.end())
        name_table[name1] = pair<double, int>(value, 1);
    else {
        pair<double, int> v = name_table[name1];
        name_table[name1] = pair<double, int>(v.first + value, v.second + 1);
    }

    is.get(sp);
    if (sp != '\n') {
        // use cin, there is newline here
        // use stringstream, no newline
        is.putback(sp);
    }

    return true;
}

string ex[] = {"val name1 1",
    "val name2 2",
    "val name3 3",
    "val name1 4",
    "val name2 5"};

int main(void)
{
    unsigned int sum = 0, mean = 0, count = 0;
    for (auto line: ex) {
        istringstream is {line};
        get_name(is);
    }

    cout << "---- print table\n";
    for (auto entry : name_table) {
        cout << entry.first << ":" << entry.second.first << "," << entry.second.second \
         << " mean=" << entry.second.first / entry.second.second << endl;
    }

    cout << "---- check all names in the table\n";
    for (auto entry : name_table) {
        count += entry.second.second;
        sum += entry.second.first;
    }
    cout << "sum=" << sum << " mean=" << sum/count << endl;

    // test find_nth
    int* array = new int[count];
    int array_index = 0;
    for (auto entry: name_table) {
        for (int i = 0; i < entry.second.second; i++) {
            array[array_index++] = entry.second.first;
        }
    }
    for (int i = 0; i < count; i++) {
        cout << array[i] << endl;
    }
    cout << "median=" << find_nth(array, array_index, array_index / 2) << endl;

    return 0;
}