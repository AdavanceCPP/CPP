#include <iostream>
#include <thread>
#include <mutex>
#include<shared_mutex>
using namespace std;

int value = 0;
std::mutex mt;
std::shared_mutex smtx;

// Reads the value and set's v to that value
void readValue(int& v)
{
	//smtx.lock_shared();
	lock_guard<shared_mutex> guard1(smtx);
	// Simulate some latency
	std::this_thread::sleep_for(std::chrono::seconds(1));
	v = value;
	//smtx.unlock_shared();
}

// Sets value to v
void setValue(int v)
{
	lock_guard<mutex> guard(mt);
	//mt.lock();
	// Simulate some latency
	std::this_thread::sleep_for(std::chrono::seconds(1));
	value = v;
	//mt.unlock();
}

int main()
{
	int read1, read2, read3;

	thread t1(readValue, std::ref(read1));
	thread t2(readValue, std::ref(read2));
	
	thread t3(readValue, std::ref(read3));
	thread t4(setValue, 1);

	t1.join();
	t2.join();
	t3.join();
	t4.join();

	cout << read1 << "\n";
	cout << read2 << "\n";
	cout << read3 << "\n";
	cout << value << "\n";

	return 0;
}