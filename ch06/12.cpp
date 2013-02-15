#include <iostream>
#include <map>
#include <iterator>
#include <algorithm>
#include <vector>

using namespace std;


map<string, double> table_val;
map<string, int> table_count;


int main(void)
{
    string name;
    double number;

    while (cin >> name)
    {
        cin >> number;

        if (table_val.find(name) != table_val.end())
        {
            table_val[name] = table_val[name] + number;
        }
        else
        {
            table_val[name] = number;
        }

        table_count[name]++;
    }

    double total_val = 0;
    int total_count = 0;
    
    for (map<string,double>::iterator iter = table_val.begin();
         iter != table_val.end();
         iter++)
    {
        cout << (*iter).first << ":sum=" << iter->second << ":aver=" << (*iter).second/table_count[(*iter).first] << endl;
        total_val += (*iter).second;
    }

    for (map<string,int>::iterator iter = table_count.begin();
         iter != table_count.end();
         iter++)
    {
        total_count += iter->second;
    }

    cout << "total:sum=" << total_val << ":aver=" << total_val/total_count << endl;

    vector<double> sorted_vals;
    
    for (map<string,double>::iterator iter = table_val.begin();
         iter != table_val.end();
         iter++)
    {
        sorted_vals.push_back(iter->second);
    }
    sort(sorted_vals.begin(), sorted_vals.end());

    for (vector<double>::const_iterator p = sorted_vals.begin();
         p != sorted_vals.end();
         ++p)
    {
        cout << *p << endl;
    }

    int median_index = (sorted_vals.size()/2)+1;
    cout << "median=" << sorted_vals[median_index] << endl;

    return 0;
}
