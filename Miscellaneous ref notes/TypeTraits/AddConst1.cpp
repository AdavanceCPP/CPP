#include<iostream>
#include<type_traits>
using namespace std;

class CA
{
public:
	void fun() { cout << "CA fun() called" << endl; }
	void fun() const { cout << "CA fun() const called" << endl; }
	void fun() volatile { cout << "CA fun() volatile called" << endl; }
	void fun() const volatile { cout << "CA fun() const volatile called" << endl; }
};

int main()
{
	CA obj1;
	add_const<CA>::type obj2;
	add_volatile<CA>::type obj3;
	add_cv<CA>::type obj4;
	obj1.fun();
	obj2.fun();
	obj3.fun();
	obj4.fun();
	return 0;
}