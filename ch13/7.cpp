#include <iostream>
#include <map>
#include <fstream>


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

    fst.open("7.txt");

    while (fst.eof() == false)
    {
        int i;
        string s;
    
        fst >> s;

        fst >> i;

        cout << s << i << endl;

        if (s == "")
            break;
        
        mystore.store[s] = i;
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
