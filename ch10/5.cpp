#include <iostream>

using namespace std;

class Out_of_range {};
class Wrong_value {};

class Histogram
{
public:
    Histogram(int start, int end, int interval);
    ~Histogram();

    void set_count(int value, int count);
    void print_count(void);

    //private:
    int *count_table;
    int table_size;
    int start, end, interval;
};


Histogram::Histogram(int start, int end, int interval)
{
    table_size = ((end - start)/interval) + 1;
    count_table = new int[table_size];

    this->start = start;
    this->end = end;
    this->interval = interval;
}

Histogram::~Histogram()
{
    delete[] count_table;
}

void Histogram::set_count(int value, int count)
{
    if (value > end)
        throw Out_of_range();

    if (value % interval != 0)
        throw Wrong_value();
    
    count_table[value/interval] = count;
}

void Histogram::print_count(void)
{
    for (int i = start; i <= end; i += interval)
    {
        cout << i << ":";

        for (int bar_size = count_table[i/interval] / 10;
             bar_size > 0;
             bar_size--)
            cout << "=";

        cout << endl;
    }
}

int main(void)
{
    Histogram h(0, 100, 2);

    cout << (void *)h.count_table << ":" << h.table_size << endl;

    for (int i = 0; i < 50; i += 10)
        h.set_count(i, i);

    h.print_count();

    try {
        h.set_count(200, 200);
    } catch (Out_of_range e) {
        cout << "out_of_range error\n";
    }

    try {
        h.set_count(3, 20);
    } catch (Wrong_value e) {
        cout << "wrong_value error\n";
    }

    for (int i = 0; i <= 100; i += 2)
        h.set_count(i, i);

    h.print_count();
        
    
}
