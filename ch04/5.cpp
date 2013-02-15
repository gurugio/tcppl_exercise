#include <iostream>
#include <limits>
using namespace std;


int main(void)
{
    cout << "Minimum value for char: " << (int)numeric_limits<char>::min() << endl;
    cout << "Maximum value for char: " << (int)numeric_limits<char>::max() << endl;

    cout << "Minimum value for int: " << numeric_limits<int>::min() << endl;
    cout << "Maximum value for int: " << numeric_limits<int>::max() << endl;

    cout << "Minimum value for double: " << numeric_limits<double>::min() << endl;
    cout << "Maximum value for double: " << numeric_limits<double>::max() << endl;

    
    return 0;
}
