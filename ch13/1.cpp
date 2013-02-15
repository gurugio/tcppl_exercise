#include <iostream>

using namespace std;

template<class T> class List {
    struct Link {
        Link *pre;
        Link *suc;
        T val;
        Link(Link *p, Link *s, const T &v): pre(p), suc(s), val(v) {}
    };

    Link *head;
public:
    List() : head(0) {}
    List(const T &t): head(new Link(0, 0, t)) {}

    void add(const T &t);
    
    void print_all() const {
        for (Link *p = head; p; p = p->suc)
            cout << p->val << endl;
    }
};


template<class T> void List<T>::add(const T &t)
{
    Link *item = new Link(0, 0, t);


    
    if (head == NULL)
        head = item;
    else if (head->suc == NULL) {
        head->suc = item;
        item->pre = head;
    } else {
        head->suc->pre = item;
        item->suc = head->suc;
        head->suc = item;
        item->pre = head;
    }

    cout << (void *)item << ":" << item->suc << ":" << item->pre << endl;
}


class Rec {
    int val;
};



void f(const List<int> &li, const List<Rec> &lr)
{
    li.print_all();
//    lr.print_all(); build error at compile time
}

int main(void)
{
    List<int> li;
    List<Rec> lr;

    li.add(1);
    li.add(2);
    li.add(3);

    f(li, lr);

}
