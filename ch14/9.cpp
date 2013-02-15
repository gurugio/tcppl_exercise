#include <iostream>
#include <exception>
#include <stdexcept>
#include <vector>
#include <atomic>

using namespace std;

class Lock {
public:
    static atomic<bool> lock;

    Lock(void)
    {
        while (atomic_exchange_explicit(&lock, true, std::memory_order_acquire))
            ;
        cout << "lock:" << lock << endl;;
    }

    ~Lock(void)
    {
        std::atomic_store_explicit(&lock, false, std::memory_order_release);
        cout << "lock:" << lock << endl;;

    }
};

atomic<bool> Lock::lock = ATOMIC_VAR_INIT(false);

// g++ -std=c++0x 9.cpp
int main(void)
{
    vector<int> v(4);
    
    {
        // lock is locked at until the end of block
        Lock l;
        
    }


    {
        // lock is locked at until the end of block
        Lock l;

    }

    // no lock here
}
