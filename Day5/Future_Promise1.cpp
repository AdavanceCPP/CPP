#include<iostream>
#include<thread>
#include<string>
#include<future>
using namespace std;

void MyFun(promise<string>& prm)
{
	string str("MyFun:Hello from future");
	this_thread::sleep_for(800ms);
	//...
	//...
	prm.set_value(str);
}

/*
	The parent thread reads data from the shared memory and the child thread
	writes data onto the shared memory.
*/
int main()
{
	//A promise object to store a string
	promise<string> pm;  

	//A future object to retrieve a string stored by 'pm' the promise object.
	future<string> ft = pm.get_future();
	
	
	thread th(MyFun, std::ref(pm));

	cout << "Inside main...." << endl;
	cout <<"waiting for data..." << endl;
	string str = ft.get();  //Will remain blocked till data is written by the promise instance.
	cout << str << endl;

	th.join();
}