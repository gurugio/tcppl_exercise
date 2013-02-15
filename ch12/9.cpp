#include <iostream>
#include <cstring>

using namespace std;

class Char_vec {
    int sz;
    char element[1];
public:
    static Char_vec *new_char_vec(int s);
    char &operator[](int i) { return element[i]; }

    virtual void show(void) { cout << "OKOK\n"; }
};

Char_vec *Char_vec::new_char_vec(int s)
{
    char *new_vec = new char[sizeof(Char_vec) + s];
    return (Char_vec *)new_vec;
}

class ddd {
public:
    virtual void show(void) { cout << "okok\n"; }
};

int main(void)
{
    ddd *d = new ddd;
    d->show();
    
    Char_vec *v1 = Char_vec::new_char_vec(100);


    // static function is defined at separate space from object
    cout << "v1->" << (void *)v1 << endl;
    cout << "new_char_vec->" << (void *)(v1->new_char_vec) << endl;


    // everything works fine
    (*v1)[0] = 11;

    cout << (int)(*v1)[0] << endl;

    memset(v1, 0, 100 + sizeof(Char_vec));    

    cout << (int)(*v1)[0] << endl;

    cout << (int)(*v1)[1] << endl;


    // ANSWER: virtual function cannot be managed
    // becuase this object is not created by compiler.
    v1->show();

}
