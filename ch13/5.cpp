#include <iostream>
#include <vector>
#include <cstring>

using namespace std;


template<class T> class CmpPrice {
public:
       static bool myless(T &a, T &b) { return a.price < b.price; }
};

template<class T> class CmpCount {
public:
       static bool myless(T &a, T &b) { return a.count < b.count; }
};
                      
template<class T, class C>
void sort(vector<T> &v)
{
    const size_t n = v.size();

    for (int gap = n/2; 0 < gap; gap /= 2) {
        for (int i = gap; i < n; i++) {
            for (int j = i - gap; 0 <= j; j -= gap) {
                if (C::myless(v[j + gap], v[j]))
                    swap(v[j], v[j+gap]);
                else
                    break;
            }
        }
    }
};


class Record {
public:
    int count;
    int price;
    string name;

    Record(int c, int p, string n): count(c), price(p), name(n) {}
    bool operator<(Record &re)
    {
        return this->price < re.price;
    }
    
};


int main(void)
{
    Record a(4, 40, "a");
    Record b(3, 30, "b");
    Record c(5, 50, "c");
    Record d(7, 70, "d");
    Record e(6, 60, "e");
    Record f(1, 10, "f");
    vector<Record>::iterator it;
    
    vector<Record> vr;
    vr.push_back(a);
    vr.push_back(b);
    vr.push_back(c);
    vr.push_back(d);
    vr.push_back(e);
    vr.push_back(f);


    cout << "myvector contains:";
    for ( it=vr.begin() ; it < vr.end(); it++ )
        cout << " " << (*it).price;
    cout << endl;


    sort<Record,CmpPrice<Record> >(vr);

        

    cout << "myvector contains:";
    for ( it=vr.begin() ; it < vr.end(); it++ )
        cout << " " << (*it).price;
    cout << endl;

    cout << "myvector contains:";
    for ( it=vr.begin() ; it < vr.end(); it++ )
        cout << " " << (*it).count;
    cout << endl;


    sort<Record,CmpCount<Record> >(vr);

        

    cout << "myvector contains:";
    for ( it=vr.begin() ; it < vr.end(); it++ )
        cout << " " << (*it).count;
    cout << endl;
    
    
    return 0;
}
