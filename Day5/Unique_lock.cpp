#include<iostream>
#include<thread>
#include<mutex>
using namespace std;

mutex m;

void fun()
{
    /*
        Unlike lock_guard, an unique_lock instance can call the 'lock' and 'unlock' function
        more than once, and still be exception safe.
    */
	unique_lock<mutex> locker(m, defer_lock);  
	cout <<"### non-critical section code statement - A" << endl;
    cout <<"### non-critical section code statement - B" << endl;
	//Code for synchronizing starts here....
	//Thereby now acquire the lock
	locker.lock();
	cout <<"### critical section code statement - 1" << endl;
    cout <<"### critical section code statement - 2" << endl;
	locker.unlock();   //unlock the mutex 

	//... some business here which does not require a mutex locking here...
    cout <<"### non-critical section code statement - C" << endl;
    cout <<"### non-critical section code statement - D" << endl;
	//Code for synchronizing starts here....
	//Thereby now acquire the lock
	locker.lock();
	cout <<"### critical section code statement - 3" << endl;
    cout <<"### critical section code statement - 4" << endl;
	locker.unlock();   //unlock the mutex 
}

int main()
{
	thread th1(&fun);
	thread th2(&fun);

	th1.join();
	th2.join();
	return 0;
}