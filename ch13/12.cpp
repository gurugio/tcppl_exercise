#include <iostream>
#include <map>
#include <fstream>
#include <cstring>
#include <cstdlib>

using namespace std;


template<class K, class V>
class Store {
public:
    map<K,V> store;
};


int main(void)
{
    ifstream fst;
    Store<string, int> mystore;
    char cbuf[100];

    fst.open("12.txt");

    while (fst.getline(cbuf, 99))
    {

        cout << cbuf << endl;
        
        int i = strlen(cbuf) - 1;


        while(cbuf[i] != ' ')
            i--;
    
        cbuf[i] = 0;
        string name = cbuf;
        int num = atoi(&cbuf[i+1]);

        cout << name << num << endl;

        mystore.store[name] = num;
    }

    fst.close();


    map<string,int>::iterator it;
    int sum = 0;

    // show content:
    for ( it=mystore.store.begin() ; it != mystore.store.end(); it++ ) {
        cout << (*it).first << " => " << (*it).second << endl;
        sum += (*it).second;
    }

    cout << sum << endl;
}
