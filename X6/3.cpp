#include <iostream>
#include <future>
#include <thread>         // std::this_thread::sleep_for
#include <chrono>         // std::chrono::seconds
#include <limits>

using namespace std;
using namespace std::chrono;

int main(void)
{

	auto t0 = high_resolution_clock::now();
	
	for (volatile int i = 0; i < numeric_limits<int>::max(); i++)
		continue;
	
	auto t1 = high_resolution_clock::now();

	cout << duration_cast<milliseconds>(t1 - t0).count() << "msec\n";
}

/*
gkim@laptop:~/tcppl_exercise/X6$ g++ 3.cpp
gkim@laptop:~/tcppl_exercise/X6$ ./a.out
3997msec
gkim@laptop:~/tcppl_exercise/X6$ g++ -O2 3.cpp
gkim@laptop:~/tcppl_exercise/X6$ ./a.out
2529msec
gkim@laptop:~/tcppl_exercise/X6$ 
*/
