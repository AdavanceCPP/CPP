#include<iostream>
#include<thread>
using namespace std;
static thread_local int z = 10;

void fun1()
{
	z++;
	this_thread::sleep_for(chrono::seconds(2));
	cout << "fun1, z:" << z << endl;
}
void fun2()
{
	z--;
	this_thread::sleep_for(chrono::seconds(2));
	cout << "fun2, z:" << z << endl;
}
void main()
{
	thread th1(fun1);
	thread th2(fun1);
	thread th3(&fun2);
	thread th4(&fun2);

	th1.join();
	th2.join();
	th3.join();
	th4.join();
}