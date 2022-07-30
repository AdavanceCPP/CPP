#include<iostream>
using namespace std;

[[noreturn]] void fun1()
{
	cout << "fun1() called" << endl;
}

void fun2()
{
	cout << "fun2() called" << endl;
	fun1();
	cout << "Back from fun1..." << endl;
}

void fun3()
{
	cout << "fun3() called" << endl;
	fun2();
	cout << "Back from fun2..." << endl;
}

int main()
{
	fun3();
	cout << "back from fun3..." << endl;
	return 0;
}