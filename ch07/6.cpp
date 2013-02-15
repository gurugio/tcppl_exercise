#include<iostream>
#include <fstream>
#include <cstring>

using namespace std;

typedef int (*CFT)(const void *, const void *);

void ssort(void *base, size_t n, size_t sz, CFT cmp)
{
    for (int gap = n/2; 0 < gap; gap /= 2)
    {
        for (int i = gap; i < n; i++)
        {
            for (int j = i - gap; 0 <= j; j -= gap)
            {
                char *b = static_cast<char *>(base);
                char *pj = b + j * sz;
                char *pjg = b + (j + gap) * sz;
                if (cmp(pjg, pj) < 0)
                {
                    for (int k = 0; k < sz; k++)
                    {
                        char temp = pj[k];
                        pj[k] = pjg[k];
                        pjg[k] = temp;
                    }
                }
                else
                {
                    break;
                }
            }
        }
    }
}

void my_swap(char *a, char *b, size_t sz)
{
    char temp;

    for (int k = 0; k < sz; k++)
    {
        temp = a[k];
        a[k] = b[k];
        b[k] = temp;
    }
}

void my_qsort(void *base, size_t n, size_t sz, CFT cmp)
{
    int t;
    int left, right;
    char *basep = static_cast<char *>(base);
    char *pivot;

    if (n > 1)
    {
        pivot = basep + (n-1)*sz;
        
        left = 0;
        right = n - 2; // [n-1] is pivot

        while (1)
        {
            while (cmp(basep + left * sz, pivot) < 0)
            {
                left++;
            }
            
            while (cmp(basep + right * sz, pivot) > 0)
            {
                right--;
            }
            
            if (left >= right)
                break;

            my_swap(basep + left * sz, basep + right * sz, sz);
        }
        my_swap(basep + left * sz, basep + (n-1) * sz, sz);

        my_qsort(basep, left, sz, cmp);
        my_qsort(basep + (left+1)*sz, n - left - 1, sz, cmp);
    }
}


struct User {
    char *name;
    char *id;
    int dept;
};

User heads[] = {
    {"Citchie DM", "dmr", 11271},
    "Bethi R", "ravi", 11272,
    "Azymanski TG", "rgs", 11273,
    "Bchryer NL", "nls", 11274
};

void print_id(User *v, int n)
{
    for (int i = 0; i < n; i++)
        cout << v[i].name << '\t' << v[i].id << '\t' << v[i].dept << '\n';
}

int cmp1(const void *p, const void *q)
{
    return strcmp(static_cast<const User *>(p)->name,
                  static_cast<const User *>(q)->name);
}

int cmp2(const void *p, const void *q)
{
    return static_cast<const User *>(p)->dept - static_cast<const User *>(q)->dept;
}

int cmp_int(const void *p, const void *q)
{
    const int *a = static_cast<const int *>(p);
    const int *b = static_cast<const int *>(q);

    return *a - *b;
}

int main(void)
{
    int ddd[] = {3, 8, 4, 6, 5, 4, 1, 2, 7, 9, 5, 10};
    my_qsort(ddd, sizeof(ddd)/sizeof(int), sizeof(int), cmp_int);

    for (int i = 0; i < sizeof(ddd)/sizeof(int); i++)
        cout << ddd[i] << ",";
    cout << endl;
    
    print_id(heads, 4);
    my_qsort(heads, 4, sizeof(User), cmp1);
    print_id(heads, 4);
}

