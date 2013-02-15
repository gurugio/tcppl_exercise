#include <iostream>

using namespace std;


template <class T> class Handle {
public:

    class runtime_error {
    public:
        runtime_error(string s) {}
    };
    
    Handle(T *p = 0) : ptr(p), use(new size_t(1)) {}

    T &operator*();
    T *operator->();

    Handle(const Handle &h) : ptr(h.ptr), use(h.use) { ++*use; }
    
    Handle &operator=(const Handle &);
    ~Handle() { rem_ref(); }
private:
    T *ptr;
    size_t *use;
    void rem_ref()
    {
        if (--*use == 0) {
            delete ptr;
            delete use;
        }
    }
};

template <class T>
inline Handle<T> &Handle<T>::operator=(const Handle &rhs)
{
    ++*rhs.use;
    rem_ref();

    ptr = rhs.ptr;
    use = rhs.use;
    return *this;
}

template <class T>
inline T &Handle<T>::operator*()
{
    if (ptr) return *ptr;
    throw runtime_error("dereference of unbound handle");
}

template <class T>
inline T *Handle<T>::operator->()
{
    if (ptr) return ptr;
    throw runtime_error("access through unbound handle");
}



int main(void)
{
    Handle<int> hp(new int(32));

    Handle<int> hp2 = hp;

    cout << *hp << ":" << *hp2 << endl;

    *hp2 = 10;
    
    cout << *hp << ":" << *hp2 << endl;
    
}
    
