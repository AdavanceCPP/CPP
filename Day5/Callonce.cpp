#include<iostream>
#include<mutex>
#include<thread>
using namespace std;

once_flag Once;

void Business1()
{
	cout <<"Business1 execution started..." << endl;
	cout <<"##################" << endl;

	auto lm = []() {cout << "inside lambda" << endl; };
	//lm();
	call_once(Once, lm);

	cout <<"##################" << endl;
	cout <<"Business1 execution completed..." << endl;
	
}

int main()
{
	// Business1();
	// Business1();
	thread th1(Business1);
	th1.join();
	cout<<"--------------------" << endl;
	thread th2(Business1);
	th2.join();
	cout<<"--------------------" << endl;
	thread th3(Business1);
	th3.join();
	cout<<"--------------------" << endl;
	return 0;
}