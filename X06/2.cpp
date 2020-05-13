#include <iostream>
#include <future>
#include <thread>         // std::this_thread::sleep_for
#include <chrono>         // std::chrono::seconds

using namespace std;


void async_say_hello(void)
{
	for (int i = 0; i < 5; i++) {
		cout << "hello\n";
		this_thread::sleep_for (std::chrono::seconds(1));
	}
}

void async_say_world(void)
{
	for (int i = 0; i < 5; i++) {
		cout << "world\n";
		this_thread::sleep_for (std::chrono::seconds(1));
	}
}

struct thr_say_hello {
	void operator()() {
		for (int i = 0; i < 5; i++) {
			cout << "thr-hello\n";
			this_thread::sleep_for (std::chrono::seconds(1));
		}
	};
};

struct thr_say_world {
	void operator()() {
		for (int i = 0; i < 5; i++) {
			cout << "thr-world\n";
			this_thread::sleep_for (std::chrono::seconds(1));
		}
	};
};

int main(void)
{
	auto f0 = async(async_say_hello);
	auto f1 = async(async_say_world);

	thread t1 {thr_say_hello()};
	thread t2 {thr_say_world()};
	t1.join();
	t2.join();
}
