#include<iostream>
#include<thread>
#include<future>
using namespace std;
//Like Thread class objects, Even the future and promise class objects are
//move only types.
int factorial(future<int>& f)
{
	int res=1;
	cout <<"Waiting for data to be written" << endl;
	int N = f.get();
   cout <<"Retrieved data from shared memory.." << endl;
	for(int i=1;i<=N;i++)
	{
		res *= i;
	}
	return res;
}
/*
   A write business in the parent thread and a read business in the child thread.
   Spawning threads using 'async' call.
*/
int main()
{
   int x;
   //create a future object channel to send a value from parent thread to 
   //to the child thread, 
   promise<int> p;
   future<int> f = p.get_future();
   
   future<int> fu = async(launch::async, factorial, ref(f));
   
   //do someother parent thread business....
   //also take a nap if necessary
   cout <<"Bit busy - PARENT THREAD...." << endl;
   this_thread::sleep_for(1s);
   //And now it is decided to pass the required parameter to child thread
   cout <<"Writing data......." << endl;
   p.set_value(4);
   
   
   x = fu.get();
   cout <<"Factorial value recieved from child thread is "<< x << endl;

   return 0;
}