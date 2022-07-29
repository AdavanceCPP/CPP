#include<iostream>
#include<thread>
using namespace std;

void fun1(int x)
{
	x = x + 10;
	cout << "fun1(int x) called from thread, x= :" <<x << endl;
}

void fun2(int &x)
{
	x = x + 10;
	cout << "fun2(int &x) called from thread, x= :" << x << endl;
}

int main()
{
	int y = 100;

	thread th1(fun1,y);  // by default parameters to thread functions are always
	                    // passed by value
	
	th1.join();
	cout << "main thread, y : " << y << endl;

	cout << "Upon spawning second thread" << endl;
	thread th2(fun2, std::ref(y));
	th2.join();

	cout << "main thread, y : " << y << endl;

    
	return 0;
}