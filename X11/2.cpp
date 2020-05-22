#include <iostream>
#include <string>
#include <map>
#include <sstream>

using namespace std;

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

    return 0;
}

/*
gkim@gkim-laptop:~/tcppl_exercise/X11$ g++ -g 2.cpp && ./a.out
val name1:1
val name2:2
val name3:3
val name1:4
val name2:5
---- print table
val name1:5,2 mean=2.5
val name2:7,2 mean=3.5
val name3:3,1 mean=3
---- check all names in the table
sum=15 mean=3
*/