#include <iostream>
#include <vector>

using namespace std;


template<class T> class my_compare {
public:
    static bool cmp(T &a, T &b)
    {
        return a < b;
    }
};


template<class T>
void copy_vec(vector<T> &src, vector<T> &dst, int s, int cnt)
{
    for(int i = s, j = 0; j < cnt; i++, j++) {
        dst.push_back(src[i]);
    }
}

template<class T, class CMP>
void my_qsort(vector<T> &base, int n)
{
    int t;
    int left, right;
    int pivot;

    if (n > 1)
    {
        pivot = n-1;
        
        left = 0;
        right = n - 2; // [n-1] is pivot

        cout << pivot << ":" << left << ":" << right << endl;
        
        while (1)
        {
            while (CMP::cmp(base[left], base[pivot]) == true)
            {
                left++;
                cout << "left=" << left << endl;
            }
            
            while (CMP::cmp(base[right], base[pivot]) == false)
            {
                cout << "right=" << right << endl;
                right--;
            }


            cout << left << "===" << right << endl;

            if (left >= right)
                break;

            swap(base[left], base[right]);
        }
        swap(base[left], base[pivot]);

        my_qsort<T, CMP>(base, left);

        vector<T> tmp;
        copy_vec<T>(base, tmp, left+1, n - left - 1);

        my_qsort<T, CMP>(tmp, n - left - 1);
    }
};

class Record {
public:
    int count;
    int price;
    string name;

    Record(int c, int p, string n): count(c), price(p), name(n) {}
    bool operator<(Record &re)
    {
        return this->price < re.price;
    }
    
};


int main(void)
{
    Record a(4, 40, "a");
    Record b(3, 30, "b");
    Record c(5, 50, "c");
    Record d(7, 70, "d");
    Record e(6, 60, "e");
    Record f(1, 10, "f");
    vector<Record>::iterator it;
    
    vector<Record> vr;
    vr.push_back(a);
    vr.push_back(b);
    vr.push_back(c);
    vr.push_back(d);
    vr.push_back(e);
    vr.push_back(f);


    cout << "myvector contains:";
    for ( it=vr.begin() ; it < vr.end(); it++ )
        cout << " " << (*it).price;
    cout << endl;


    cout << my_compare<Record>::cmp(a, e) << endl;

    vector<Record> tmp;
    copy_vec<Record>(vr, tmp, 2, 4);
    for ( it=tmp.begin() ; it < tmp.end(); it++ )
        cout << " " << (*it).price;
    cout << endl;
    
    
    my_qsort<Record, my_compare<Record> >(vr, 6);
        

    cout << "myvector contains:";
    for ( it=vr.begin() ; it < vr.end(); it++ )
        cout << " " << (*it).price;
    cout << endl;

}
