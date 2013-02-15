#include <iostream>
#include <sstream>
#include <string>


using namespace std;


template<class NAME, class COUNT, class PRICE>    
void readline(NAME &name, COUNT &count, PRICE &price)
{
    char c;
    char cbuf[100];
    int index;
    string tmp;
    istringstream is1, is2, is3;;

    
    do {
        cin.get(c);
    } while (c != '(');

    // first
    index = 0;
    do {
        c = cin.get();

        cbuf[index] = c;
        index++;
    } while (c != ',' && c != ')');
    cbuf[index - 1] = 0;

    if (c == ')') return;

    
    tmp = cbuf;
    is1.str(tmp);

    is1 >> name;

    // second
    index = 0;
    do {
        c = cin.get();

        cbuf[index] = c;
        index++;
    } while (c != ',' && c != ')');
    cbuf[index - 1] = 0;

    if (c == ')') return;


    tmp = cbuf;

    is2.str(tmp);
    is2 >> count;


    // third
    index = 0;
    do {
        c = cin.get();
        cbuf[index] = c;
        index++;
    } while (c != ',' && c != ')');
    cbuf[index - 1] = 0;
    
    
    tmp = cbuf;
    is3.str(tmp);
    is3 >> price;

}


int main(void)
{
    string n;
    int c;
    int p;
    
    readline(n, c, p);

    cout << n << c << p << endl;

    string nn;
    double cc;
    double pp;
    readline(nn, cc, pp);
    cout << nn << cc << pp << endl;
    

}
