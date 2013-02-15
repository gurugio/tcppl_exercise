#include <iostream>
#include <set>

using namespace std;

class Intset {
public:
    Intset() { iset = new set<int>; }
    void insert(int n) { iset->insert(n); }
    void print(void);
    Intset &union_set(Intset &with);
    set<int>::iterator get_begin(void) { iset->begin(); }
    set<int>::iterator get_end(void) { iset->end(); }
    
private:
    set<int> *iset;
};


void Intset::print(void)
{
    for (set<int>::iterator it = iset->begin();
         it != iset->end();
         it++)
    {
        cout << *it << endl;
    }
}


Intset &Intset::union_set(Intset &with)
{
    Intset *result_set = new Intset();

    *result_set = *this;

    for (set<int>::iterator it = with.get_begin();
         it != with.get_end();
         it++)
    {
        cout << "union-" << *it << endl;
        result_set->insert(*it);
    }
    
    
    return *result_set;
}


int main(void)
{
    Intset set1, set2;

    set1.insert(1);
    set1.insert(2);
    set1.insert(3);
    set1.insert(4);
    set1.insert(4);
    set1.insert(4);

    set1.print();

    set2.insert(1);
    set2.insert(2);
    set2.insert(33);
    set2.insert(44);
    set2.insert(444);
    set2.insert(4444);

    set2.print();

    Intset &tmp = set1.union_set(set2);
    tmp.print();
};
