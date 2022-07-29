#include<iostream>
#include<thread>
#include<mutex>
#include<string>
using namespace std;

mutex mu;
/*
void print(string s, int val)  //use RAII technique
{
	//automatically acquires lock on entry and unlocks on exit
	lock_guard<mutex> guard(mu);   //more safe even upon an exception 
	cout << s << val << endl;
	//...
	//...
}

void Decrement()
{
	for (int i = -1; i > -100; i--)
	{
		print("Decrement :", i);
	}
}
void Increment()
{
	for (int i = 1; i < 100; i++)
	{
		print("Increment :", i);
	}
}

*/
void Decrement()
{
	lock_guard<mutex> guard(mu);  
	for (int i = -1; i > -100; i--)
	{
		 //mu.lock();
		cout << "Decrement :" << i << endl;
		//..
		//..
		//mu.unlock();
	}
}

void Increment()
{
	lock_guard<mutex> guard(mu);  
	for (int i = 1; i<100; i++)
	{
		//mu.lock();
		cout <<"Increment :"<< i << endl;
		//mu.unlock();
	}
}

int main()
{
	thread th1(Increment);
	thread th2(Decrement);
	th1.join();
	th2.join();

	return 0;
}