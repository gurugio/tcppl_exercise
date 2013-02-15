#include <iostream>

using namespace std;


typedef char T;

class Ptr_to_T {
    T *p;
    T *array;
    int size;
public:

    class range {};
    
    Ptr_to_T(T *p, T *v, int s);
    Ptr_to_T(T *p);

    Ptr_to_T &operator++();
    Ptr_to_T operator++(int);

    Ptr_to_T &operator--();
    Ptr_to_T operator--(int);

    T &operator*();
    Ptr_to_T &operator=(T d);
};

Ptr_to_T::Ptr_to_T(T *p, T *v, int s) : p(p), array(v), size(s)
{

}

Ptr_to_T::Ptr_to_T(T *p) : p(p)
{
    array = 0;
    size = 1;
}

T &Ptr_to_T::operator*(void)
{
    return *p;
}

Ptr_to_T &Ptr_to_T::operator=(T d)
{
    *p = d;
    return *this;
}


Ptr_to_T &Ptr_to_T::operator++()
{
    if ((p - array) >= size) throw range();
    
    p++;
    return *this;
}

Ptr_to_T Ptr_to_T::operator++(int)
{
    if ((p - array) >= size) throw range();

    Ptr_to_T temp = *this;
    p++;
    return temp;
}

Ptr_to_T &Ptr_to_T::operator--()
{
    if (p <= array) throw range();
    p--;
    return *this;
}

Ptr_to_T Ptr_to_T::operator--(int)
{
    if (p <= array) throw range();
    Ptr_to_T temp = *this;
    p--;
    return temp;
}


int main(void)
{
    char msg[] = "abcdefghijklmnopqrstuvwxyz";

    Ptr_to_T p_msg(&msg[0], msg, sizeof(msg));
    
    *p_msg = 'X';
    cout << msg << endl;


    cout << *p_msg << endl;

    cout << *p_msg++ << endl;
    cout << *p_msg++ << endl;
    cout << *p_msg << endl;

    cout << *++p_msg << endl;
    cout << *++p_msg << endl;
    cout << *p_msg << endl;

    cout << *--p_msg << endl;
    cout << *--p_msg << endl;

    cout << *p_msg-- << endl;
    cout << *p_msg-- << endl;

    cout << *p_msg << endl;

    p_msg = T('Y');
    cout << *p_msg << endl;

    cout << *--p_msg << endl;

}

