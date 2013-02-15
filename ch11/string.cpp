#include <iostream>
#include <cstring>

using namespace std;


class String {
    //struct Srep;

    struct Srep {
        char *s;
        int sz;
        int n;  // reference count

        Srep(int nsz, const char *p)
        {
            n = 1;
            sz = nsz;
            s = new char[sz+1];
            strcpy(s, p);
        }

        ~Srep() { delete[] s; }

        Srep *get_own_copy()
        {
            if (n == 1) return this;
            n--;
            return new Srep(sz, s);
        }

        void assign(int nsz, const char *p)
        {
            if (sz != nsz) {
                delete[] s;
                sz = nsz;
                s = new char[sz+1];
            }
            strcpy(s, p);
        }

    private:
        Srep(const Srep &);
        Srep &operator=(const Srep &);
    };

    Srep *rep;
    //class Cref;
    class Cref {
        friend class String;
        String &s;
        int i;
        Cref(String &ss, int ii) : s(ss), i(ii) {}
        Cref(const Cref &r) : s(r.s), i(r.i) {}
        Cref();
    public:
        operator char() const { s.check(i); return s.read(i); }
        void operator=(char c) { s.write(i, c); }
    };

public:
    class Range{};

    String();
    String(const char *);
    String(const String &);
    String &operator=(const char *);
    String &operator=(const String &);
    ~String();


    // 여기에서 rep 즉 Srep 클래스를 사용한다.
    // 그런데 책에 있는 소스대로 컴파일하면 rep가 잘못된 사용이라고 나온다.
    // rep를 사용하기 전에 Srep 클래스가 완전하게 정의되어야하는데
    // 선언만 되어있어서 그런 컴파일 에러가 발생한다.
    // check 함수의 정의를 Srep 클래스의 정의 다음에 두면
    // 이런 에러가 생기지 않는다.
    // 아니면 이렇게 Srep 클래스의 정의를 check 함수 이전에 두면 된다.
    void check(int i) const { if (i < 0 || rep->sz <= i) throw Range(); }

    char read(int i) const { return rep->s[i]; }
    void write(int i, char c) { rep = rep->get_own_copy(); rep->s[i] = c; }

    Cref operator[](int i) { check(i); return Cref(*this, i); }
    char operator[](int i) const { check(i); return rep->s[i]; }

    int size() const { return rep->sz; }
    

    String &operator+=(const String &);
    String &operator+=(const char *);

    friend ostream &operator<<(ostream &, const String &);
    friend istream &operator>>(istream &, String &);

    friend bool operator==(const String &x, const char *s)
    { return strcmp(x.rep->s, s) == 0; }

    friend bool operator==(const String &x, const String &y)
    { return strcmp(x.rep->s, y.rep->s) == 0; }

    friend bool operator!=(const String &x, const char *s)
    { return strcmp(x.rep->s, s) != 0; }

    friend bool operator!=(const String &x, const String &y)
    { return strcmp(x.rep->s, y.rep->s) != 0; }
};





String::String()
{
    rep = new Srep(0, "");
}

String::String(const String &x)
{
    x.rep->n++;
    rep = x.rep;
}

String::~String()
{
    if (--rep->n == 0) delete rep;
}

String &String::operator=(const String &x)
{
    x.rep->n++;
    if (--rep->n == 0) delete rep;
    rep = x.rep;
    return *this;
}

String::String(const char *s)
{
    rep = new Srep(strlen(s), s);
}

String &String::operator=(const char *s)
{
    if (rep->n == 1)
        rep->assign(strlen(s), s);
    else {
        rep->n--;
        rep = new Srep(strlen(s), s);
    }

    return *this;
}


String operator+(const String &, const String &);
String operator+(const String &, const char *);




    

String f(String a, String b)
{
    a[2] = 'x';
    char c = b[3];
    cout << "in f:" << a << ' ' << b << ' ' << c << '\n';
    return b;
}

int main()
{
    String x, y;
    cout << "Please enter two strings\n";
    cin >> x >> y;
    cout << "input:" << x << ' ' << y << '\n';
    String z = x;
    y = f(x, y);
    if (x != z) cout << "x corrupted!\n";
    x[0] = '!';
    if (x == z) cout << "write failed\n";
    cout << "exit:" << x << ' ' << y << 'x' << z << '\n';
}

