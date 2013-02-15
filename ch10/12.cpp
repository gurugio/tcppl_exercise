#include <iostream>
#include <list>

using namespace std;

class CharQueue {
public:
    CharQueue(void);
    void insertq(char);
    char extractq(void);
    void print(void);
    bool empty(void);
private:
    list<char> *queue;
};


CharQueue::CharQueue(void)
{
    queue = new list<char>;
    cout << "Q start\n";
}


void CharQueue::insertq(char c)
{
    queue->push_front(c);
}

char CharQueue::extractq(void)
{
    char ret = queue->back();
    queue->pop_back();
    return ret;
}

void CharQueue::print(void)
{
    for (list<char>::iterator it = queue->begin(); it != queue->end() ; ++it)
        cout << " " << *it;
    cout << endl;
}

bool CharQueue::empty(void)
{
    return queue->empty();
}


int main(void)
{
    CharQueue q;

    q.insertq('a');
    q.insertq('b');
    q.insertq('c');
    q.insertq('d');
    q.insertq('e');
    q.insertq('f');
    q.insertq('g');

    q.print();

    while (q.empty() != true)
    {
        char c = q.extractq();
        cout << c << endl;
    }
}
