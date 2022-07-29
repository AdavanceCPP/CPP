#include<iostream>
#include<thread>
#include<mutex>
using namespace std;

std::mutex mx1;
std::recursive_mutex mx2;

void fun(int n) 
{
	//lock_guard<mutex> guard(mx1);
	lock_guard<recursive_mutex> guard(mx2);
	cout << "value of n" << n << endl;
	if (n == 1)
	{
		cout << "-------------" << endl;
		return;
	}
	else
	{
		--n;
		fun(n);   //recursive call here
	}
}

int main()
{
	
	thread th1(fun,10);
	thread th2(fun, 20);

	th1.join();
	th2.join();
	return 0;
}