#include <iostream>
#include <vector>

using namespace std;

#if 0
class Assoc {
    struct Pair {
        string name;
        double val;
        Pair(string n = "", double v = 0): name(n), val(v) {}
    };
    vector<Pair> vec;

    Assoc(const Assoc &);
    Assoc &operator=(const Assoc &);

public:
    Assoc() {}
    const double &operator[](const string &);
    double &operator[](string &);
    void print_all() const;
};

double &Assoc::operator[](string &s)
{
    for (vector<Pair>::iterator p = vec.begin(); p != vec.end(); ++p) {
        if (s == p->name) return p->val;
    }

    vec.push_back(Pair(s, 0));
    return vec.back().val;
}

void Assoc::print_all() const
{
    for (vector<Pair>::const_iterator p = vec.begin(); p != vec.end(); p++)
        cout << p->name << ":" << p->val << endl;
}
#endif

struct Pair {
    string name;
    double val;
    Pair(string n = "" , double v = 0): name(n), val(v) {}
};

template<class TYPE>
class Assoc {

    vector<Pair> vec;

    Assoc(const Assoc &);
    Assoc &operator=(const Assoc &);

public:
    Assoc() {}
//    const double &operator[](const string &);
    double &operator[](TYPE );
    void print_all() const;
};

template<class TYPE> double &Assoc<TYPE>::operator[](TYPE s)
{
    string *str = new string(s);
    vector<Pair>::iterator p;
    
    for (p = vec.begin(); p != vec.end(); ++p) {
        if (s == p->name) return p->val;
    }

    vec.push_back(Pair(*str, 0));
    return vec.back().val;
}

template<class TYPE> void Assoc<TYPE>::print_all() const
{
    for (vector<Pair>::const_iterator p = vec.begin(); p != vec.end(); p++)
        cout << p->name << ":" << p->val << endl;
}


int main(void)
{
    // both work well
    
    string buf;
    Assoc<string> vec;
    while (cin >> buf) vec[buf]++;
    vec.print_all();

    // char cbuf[100];
    // Assoc<char*> vec;
    // while (cin >> cbuf) vec[cbuf]++;
    // vec.print_all();
}


  
