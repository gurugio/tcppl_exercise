#include <iostream>
#include <chrono>

using namespace std;
using namespace std::chrono;

class pingpong
{
private:
	int depth_max;
	
public:
	pingpong(int d) : depth_max{d} {
		cout << "Calling-depth: " << depth_max << endl;
	}
	
	int ping_noexception(int depth)
	{
		if (depth > depth_max)
			return -1;
		//cout << depth << ":ping\n";
		return pong_noexception(depth + 1);
	}

	int pong_noexception(int depth)
	{
		if (depth > depth_max)
			return -1;
		//cout << depth << ":pong\n";
		return ping_noexception(depth + 1);
	}

	void ping_exception(int depth)
	{
		if (depth > depth_max)
			throw runtime_error{"Ping: over-depth"};

		try {
			pong_exception(depth + 1);
		} catch (exception& e) {
			//cout << "Exception from pong at depth:" << (depth + 1) << endl;
			throw;
		}
	}

	void pong_exception(int depth)
	{
		if (depth > depth_max)
			throw runtime_error{"Pong: over-depth"};

		try {
			ping_exception(depth + 1);
		} catch (exception& e) {
			//cout << "Exception from ping at depth:" << (depth + 1) << endl;
			throw;
		}
	}
	
	int play_noexception(void)
	{
		return ping_noexception(0);
	}

	void play_exception(void)
	{
		ping_exception(0);
	}
};

int main(void)
{
	pingpong tabletennis(10000);
	auto start = high_resolution_clock::now();
	// *_noexception returns error value
	int ret = tabletennis.play_noexception();
	auto end = high_resolution_clock::now();
	cout << "ret:" << ret << endl;
	cout << "time-noexception: " << duration_cast<microseconds>(end - start).count() << endl;
	// *_exception throws exception
	try {
		start = high_resolution_clock::now();
		tabletennis.play_exception();
	} catch (exception& e) {
		end = high_resolution_clock::now();
		cout << "time-exception: " << duration_cast<microseconds>(end - start).count() << endl;
	}
}

/* NO OPTIMIZATION
gkim@gkim-laptop:~/tcppl_exercise/X14$ g++ 11.cpp && ./a.out
Calling-depth: 10000
ret:-1
time-noexception: 121
time-exception: 25545
gkim@gkim-laptop:~/tcppl_exercise/X14$ g++ 11.cpp && ./a.out
Calling-depth: 10000
ret:-1
time-noexception: 125
time-exception: 25039
gkim@gkim-laptop:~/tcppl_exercise/X14$ g++ 11.cpp && ./a.out
Calling-depth: 10000
ret:-1
time-noexception: 125
time-exception: 24878
gkim@gkim-laptop:~/tcppl_exercise/X14$ g++ 11.cpp && ./a.out
Calling-depth: 10000
ret:-1
time-noexception: 123
time-exception: 25360
*/

/* -O2 OPTIMIZATION
gkim@gkim-laptop:~/tcppl_exercise/X14$ g++  -O2 11.cpp && ./a.out
Calling-depth: 10000
ret:-1
time-noexception: 0
time-exception: 21254
gkim@gkim-laptop:~/tcppl_exercise/X14$ g++  -O2 11.cpp && ./a.out
Calling-depth: 10000
ret:-1
time-noexception: 0
time-exception: 21140
gkim@gkim-laptop:~/tcppl_exercise/X14$ g++  -O2 11.cpp && ./a.out
Calling-depth: 10000
ret:-1
time-noexception: 0
time-exception: 20763
gkim@gkim-laptop:~/tcppl_exercise/X14$ g++  -O2 11.cpp && ./a.out
Calling-depth: 10000
ret:-1
time-noexception: 0
time-exception: 20987
*/
