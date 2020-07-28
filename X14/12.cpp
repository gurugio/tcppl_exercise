#include <iostream>
#include <chrono>

using namespace std;
using namespace std::chrono;

enum class ErrorSelect {
	RETURN,
	EXCEPTION
};

int func_counter = 0;

int consumer(ErrorSelect sel, unsigned int ret)
{
	func_counter++; // disable optimization roll-out function calling
	if (sel == ErrorSelect::RETURN) {
		return (ret + 1) ^ 0x12341234;
	} else {
		throw runtime_error{"error"};
	}
}

int main(void)
{
	unsigned int count = 100000;
	int ret;
	auto start = high_resolution_clock::now();
	for (unsigned int i = 0; i < count; i++) {
		ret = consumer(ErrorSelect::RETURN, i);
	}
	auto end = high_resolution_clock::now();

	// disable optimization roll-out function calling
	cout << "ret=" << ret << "counter=" << func_counter << endl;
	cout << "time-return: " << duration_cast<microseconds>(end - start).count() << endl;

	start = high_resolution_clock::now();
	for (unsigned int i = 0; i < count; i++) {
		try {
			consumer(ErrorSelect::EXCEPTION, i);
		} catch (...) {
			// do nothing
		}
	}
	end = high_resolution_clock::now();
	cout << "time-exception: " << duration_cast<microseconds>(end - start).count() << endl;
}

/*
1. Exception has no impact with O2 optimization
2. Exception-throwing always has poor performance.

gkim@gkim-laptop:~/tcppl_exercise/X14$ g++ -O2 12.cpp && ./a.out
ret=305501332counter=100000
time-return: 0
time-exception: 149777
gkim@gkim-laptop:~/tcppl_exercise/X14$ g++ -O2 12.cpp && ./a.out
ret=305501332counter=100000
time-return: 0
time-exception: 151506
gkim@gkim-laptop:~/tcppl_exercise/X14$ g++ -O2 12.cpp && ./a.out
ret=305501332counter=100000
time-return: 0
time-exception: 152427
gkim@gkim-laptop:~/tcppl_exercise/X14$ g++ -O2 12.cpp && ./a.out
ret=305501332counter=100000
time-return: 0
time-exception: 149229

gkim@gkim-laptop:~/tcppl_exercise/X14$ g++ 12.cpp && ./a.out
ret=305501332counter=100000
time-return: 269
time-exception: 150807
gkim@gkim-laptop:~/tcppl_exercise/X14$ g++ 12.cpp && ./a.out
ret=305501332counter=100000
time-return: 269
time-exception: 154556
gkim@gkim-laptop:~/tcppl_exercise/X14$ g++ 12.cpp && ./a.out
ret=305501332counter=100000
time-return: 269
time-exception: 151907
*/
