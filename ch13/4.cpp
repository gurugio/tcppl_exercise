#include <iostream>
#include <cstring>

using namespace std;

template<class C> class String;
template<class C> ostream &operator<<(ostream &, const String<C> &);

template<class C> class String {
    struct Srep {
        C *s;
        int sz;
        int n; // reference count

        Srep(int nsz, const C *p)
        {
            n = 1;
            sz = nsz;
            s = new C[sz+1];
            strcpy(s, p);
        }

        ~Srep() { delete[] s; }

        Srep *get_own_copy()
        {
            if (n == 1) return this;
            n--;
            return new Srep(sz, s);
        }

        void assign(int nsz, const C *p)
        {
            if (sz != nsz) {
                delete[] s;
                sz = nsz;
                s = new C[sz+1];
            }

            strcpy(s, p);
        }
    private:
        Srep(const Srep &);
        Srep &operator=(const Srep &);
    };
    
    Srep *rep;

    class Cref {
        friend class String;
        String &s;
        int i;
        Cref(String &ss, int ii): s(ss), i(ii) {}
        Cref(const Cref &r): s(r.s), i(r.i) {}
        Cref();
    public:
        operator C() const { s.check(i); return s.read(i); }
        void operator=(C c) { s.write(i, c); }
    };
    
public:
    class Range {};

    
    String();
    String(const C *);
    String(const String &);
    // String &operator=(const C *);
    // String &operator=(const String &);
    ~String();


    void check(int i) const { if (i < 0 || rep->sz <= i) throw Range(); }

    C read(int i) const { return rep->s[i]; }
    void write(int i, C c) { rep = rep->get_own_copy(); rep->s[i] = c; }

    Cref operator[](int i) { check(i); return Cref(*this, i); }
    C operator[](int i) const { check(i); return rep->s[i]; }

    int size() const { return rep->sz; }
    
    C *c_str() const { return rep->s; }


    friend ostream &operator<<<C>(ostream &, const String<C> &);

};


template<class C> String<C>::String()
{
    rep = new Srep(0, "");
}

template<class C> String<C>::String(const String &x)
{
    x.rep->n++;
    rep = x.rep;
}

template<class C> String<C>::~String()
{
    if (--rep->n == 0) delete rep;
}

template<class C> String<C>::String(const C *s)
{
    rep = new Srep(strlen(s), s);
}


template<class C> ostream &operator<<(ostream &os, const String<C> &str)
{
    os << str.c_str();
    return os;
}


int main(void)
{
    String<char> x = "hello";

    cout << x << endl;

    cout << x.c_str() << endl;

}
