#include <iostream>
#include <cstring>

using namespace std;

class Name {
public:
    const char *s;
    double v;

    Name(const char *s = 0, double v = 0) { this->s = s, this->v = v; }
};

class Table {
    Name *p;
    size_t sz;

public:
    Table(size_t s = 15)
    {
        p = new Name[sz = s];
    }

    Table(const Table &); // copy constructor
    Table &operator=(const Table &);
    
    ~Table()
    {
        delete[] p;
    }

    Name *lookup(const char *);
    bool insert(Name *);
};


Table::Table(const Table &t)
{
    p = new Name[sz = t.sz];
    for (int i = 0; i < sz; i++) p[i] = t.p[i];
}

Table &Table::operator=(const Table &t)
{
    if (this != &t) {
        delete[] p;
        p = new Name[sz = t.sz];
        for (int i = 0; i < sz; i++) p[i] = t.p[i];
    }

    return *this;
}

Name *Table::lookup(const char *s)
{
    for (int i = 0; i < sz; i++)
    {
        if (strcmp(p[i].s, s) == 0)
            return &p[i];
    }

    return 0;
}

bool Table::insert(Name *n)
{
    int i;
    for (i = 0; i < sz; i++)
    {
        if (p[i].s == 0)
            break;
    }

    if (i >= sz)
        return false;
    
    p[i] = *n;
    return true;
}


int main(void)
{
    Table t;

    Name a("a", 0);
    Name b("bb", 1);
    Name c("ccc", 2);


    t.insert(&a);
    t.insert(&b);
    t.insert(&c);


    Name *tt = t.lookup("bb");
    cout << tt->v << endl;
}
