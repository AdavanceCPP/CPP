#include<iostream>
using namespace std;
class Base1
{
public:
	virtual ~Base1() { }
};
class Base2
{
public:
	//no virtual destructor
};
template<typename T> class Derived :public T
{
	static_assert(has_virtual_destructor<T>::value,	"Instantiating class type must have virtual destructor");
public:
	Derived()
	{
		//static_assert(has_virtual_destructor<T>::value,	"Instantiating class type must have virtual destructor");
	}
};



void main()
{
	Derived<Base1> d1;  //OK
	//Derived<Base2> d2;   //triggers static_assert

}