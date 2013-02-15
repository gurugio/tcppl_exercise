#include <iostream>

using namespace std;



struct ddd
{
    struct ddd* next;
};

int main(void)
{
    struct ddd node = {&node};
    int a = a;

    cout << node.next << '\n';
    cout << a;
        
    return 0;
}
