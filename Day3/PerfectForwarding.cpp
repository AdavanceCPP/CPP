#include<iostream>
#include<vector>
using namespace std;
//perfect forwarding


void fun1(int& x)
{
	cout << "fun1(int& x) LVALUE called" << endl;
}

void fun1(int&& x)
{
	cout << "fun1(int&& x) RVALUE called" << endl;
}

template<typename T> void Wrap(T&& x)  // int&& &&x = 200;  int && x=200;   int x=200 
{
	//..some custom business inside the Wrap function...
	//... and later... a call to 'fun1' function...
	//fun1(x);
	fun1(std::forward<T>(x));  //perfect forwarding...
}

//consumer code------------
int main()
{
	int a = 100;

	//fun1(a);
	//fun1(200);

	Wrap(a);
	Wrap(200);
	
	return 0;
}