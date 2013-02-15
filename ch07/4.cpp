#include<iostream>
#include <fstream>

using namespace std;


int main(int argc, char *argv[])
{
    int count;
    string line;
    ifstream rf;
        
    for (count = 1; count < argc; count++)
    {
        rf.open(argv[count]);

        while ( rf.good() )
        {
            getline (rf,line);
            cout << line << endl;
        }
        
        rf.close();
    }
}
