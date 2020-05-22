#include <iostream>
#include <limits>

using namespace std;

int main(void)
{
    int32_t count = INT32_MAX;
    int32_t divider = 0;

    // cout << count / divider << endl;
    // gkim@gkim-laptop:~/tcppl_exercise/X11$ ./a.out
    // Floating point exception (core dumped)

    cout << "INT32_MAX=" << INT32_MAX << " INT32_MIN=" << INT32_MIN << endl;
    cout << count << " + 1 = " << count + 1 << endl;
    // 2147483647 -> -2147483648

    count = INT32_MIN;
    cout << count << " - 1 = " << count - 1 << endl;

    // INT32_MIN - 1 == INT32_MAX
    // INT32_MAX - 1 == INT32_MIN
}