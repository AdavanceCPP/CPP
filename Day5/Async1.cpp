#include<iostream>
#include<thread>
#include<future>
using namespace std;

class CA
{
private:
	int a, b;
public:
	CA(int x = 0, int y = 0) :a(x), b(y) { cout << "CA constructor" << endl; }
	void print()const { cout << "CA-print, a=" << a << ",b=" << b << endl; }
	void operator()(int x, int y) 
	{ 
		cout << "thread id:" << this_thread::get_id() << endl;
		cout << "CA-Functor, called" << endl; a = x; b = y; 
	}
};

void fun1() { cout << "global fun called" << endl; }

int fun2(int x)
{
	cout <<"global fun2 called" << endl;
	return x+100;
}

int main()
{
	CA obj(10,20);
	/*Launching thread's  thru 'Async' function. */
	async(&fun1);  //launch a thread with global function

	cout << "----------------" << endl;
	//launch a thread with FUNCTOR
	async(obj, 60, 70);    // async(&CA::operator()(),obj,60,70);
	obj.print();

	cout << "----------------" << endl;
	CA obj3(300, 400);
	async(&CA::print, obj3);
	cout << "----------------" << endl;

	CA obj2(30, 40);
	future<void> f2 = async(launch::deferred, &CA::print, obj2);
	//...some business here
	//now spawn the thread whose handle is future 'f2'
	f2.get();  //Spawn the thread
	cout <<"---------------------------------" << endl;
	future<int> f3 = async(launch::deferred, &fun2, 200);
	cout <<"--------------" << endl;
	cout <<"--------------" << endl;
	int x = f3.get();
	cout << x << endl;
	return 0;	
}