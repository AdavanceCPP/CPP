#include<iostream>
using namespace std;



void Business(int x) 
{ 
	cout << __FUNCTION__ << endl;
	//cout << __PRETTY_FUNCTION__ << endl;
	cout << "Int business..." << x << endl; 
}
void Business(float x) { cout << "float business..." << x << endl; }
void Business(double x) { cout << "double business..." << x << endl; }
void Business(char x) { cout << "char business..." << x << endl; }
//--------------------------------
void fun() { cout << "pack is emptied..." << endl; }

template<typename T1, typename... T2> void fun(T1 value, T2 ...args)
{
	Business(value);
	fun(args...);  
}

//consumer choice
int main()
{
	fun(10, 23, 45.12f, 56.78, 200, 'a');

	return 0;
}
