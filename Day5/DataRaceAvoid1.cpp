#include<iostream>
#include<thread>
#include<mutex>

std::mutex mtx;

using namespace std;

void Decrement()
{
    mtx.lock();
	for (int i = -1; i > -100; i--)
	{
		cout << "Decrement :" << i << endl;
	}
    mtx.unlock();
}


void Increment()
{
    mtx.lock();
	for (int i = 1; i<100; i++)
	{
		cout <<"Increment :"<< i << endl;  
	}
    mtx.unlock();
}


int main()
{
	thread th1(&Increment);
	thread th2(&Decrement);
	//..
	th1.join();
	th2.join();

	return 0;
}