#include <iostream>
#include <set>

using namespace std;


struct Node {
    int num;
};
    


class Nodeset {
public:
    Nodeset() { iset = new set<Node *>; }
    bool exist(Node &n);
    void insert(Node &n);
    void print(void);
    Nodeset &union_set(Nodeset &with);
    set<Node *>::iterator get_begin(void) { return iset->begin(); }
    set<Node *>::iterator get_end(void) { return iset->end(); }
    
private:
    set<struct Node *> *iset;
};


void Nodeset::print(void)
{
    for (set<Node *>::iterator it = iset->begin();
         it != iset->end();
         it++)
    {
        cout << (*it)->num << endl;
    }
}


bool Nodeset::exist(Node &n)
{
    for (set<Node *>::iterator it = iset->begin();
         it != iset->end();
         it++)
    {
        if ((*it)->num == n.num) // make compare function
            return true;
    }

    return false;
}

void Nodeset::insert(Node &n)
{
    if (exist(n) == false)
        iset->insert(&n);
}


Nodeset &Nodeset::union_set(Nodeset &with)
{
    Nodeset *result_set = new Nodeset();

    *result_set = *this;

    for (set<Node *>::iterator it = with.get_begin();
         it != with.get_end();
         it++)
    {
        cout << "union-" << (*it)->num << endl;
        result_set->insert(**it);
    }
    
    
    return *result_set;
}


int main(void)
{
    Node nodes[] = {1, 2, 3, 4, 5, 6};
    Node seconds[] = {1, 2, 3, 4, 11, 22, 33, 44, 55};
    Nodeset set;
    Nodeset set2;

    for (int i = 0; i < sizeof(nodes)/sizeof(Node); i++)
        set.insert(nodes[i]);
    
    set.print();

    for (int i = 0; i < sizeof(seconds)/sizeof(Node); i++)
        set2.insert(seconds[i]);
    
    set2.print();

    set.union_set(set2);

    set.print();
};
