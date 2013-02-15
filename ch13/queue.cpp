#include <iostream>

using namespace std;


template <class Type> class Queue;
template<class Type> ostream &operator<<(ostream &os, const Queue<Type> &q);

template <class Type> class QueueItem {
    friend class Queue<Type>;
    friend ostream &operator<<<Type>(ostream &os, const Queue<Type> &q);
    Type item;
    QueueItem *next;
    QueueItem(const Type &t): item(t), next(0) {}


};

template <class Type> class Queue {
public:
    Queue(): head(0), tail(0) {}

    // copy constructor
    Queue(const Queue &Q): head(0), tail(0) { copy_elems(Q); }

    Queue &operator=(const Queue &);
    ~Queue() { destroy(); }

    Type &front() { return head->item; }
    const Type &front() const { return head->item; }
    void push(const Type &);
    void pop();
    bool empty() const { return head == 0; }

    friend ostream &operator<<<Type>(ostream &os, const Queue<Type> &q);


private:
    QueueItem<Type> *head;
    QueueItem<Type> *tail;

    void destroy();
    void copy_elems(const Queue &);
};

template<class Type> void Queue<Type>::destroy()
{
    while (!empty())
        pop();
}

template<class Type> void Queue<Type>::pop()
{
    QueueItem<Type> *p = head;
    head = head->next;
    delete p;
}

template<class Type> void Queue<Type>::push(const Type &val)
{
    QueueItem<Type> *pt = new QueueItem<Type>(val);

    if (empty())
        head = tail = pt;
    else {
        tail->next = pt;
        tail = pt;
    }
}

template<class Type> void Queue<Type>::copy_elems(const Queue &orig)
{
    for (QueueItem<Type> *pt = orig.head; pt; pt = pt->next)
        push(pt->item);
}

template<class Type> Queue<Type> &Queue<Type>::operator=(const Queue &orig)
{
    return new Queue(orig);
}

template<class Type> ostream &operator<<(ostream &os, const Queue<Type> &q)
{
    os << "< ";
    QueueItem<Type> *p;
    for (p = q.head; p; p = p->next)
        os << p->item << " ";
    os << ">";
    return os;
}

int main(void)
{
    Queue<string> qs;

    qs.push(string("hello"));
    qs.push(string("world"));

    Queue<string> qcopy = qs;

    cout << qs << endl;
    cout << qcopy << endl;
    

    
}
