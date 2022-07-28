#include<iostream>
#include<memory>
using namespace std;
/*
	-Prefer unique_ptr handle over a traditional raw_pointer variable.
*/
class CA
{
public:
	CA() { cout << "CA constructor called" << endl; }
	~CA() { cout << "CA destructor called" << endl; }
	void print() { cout << "CA print called :" << this << endl; }
};

void ExceptionUnsafe()
{
	CA* p = new CA;
	//...
	cout << "custom business line1...." << endl;
	throw 100;
	cout << "custom business line2...." << endl;
	delete p;
}

void ExceptionSafe()
{
	unique_ptr<CA> p = make_unique<CA>();
	//...
	cout << "custom business line1...." << endl;
	throw 100;
	cout << "custom business line2...." << endl;
}

int main()
{
	try
	{
		//ExceptionUnsafe();
		ExceptionSafe();
	}
	catch (...) { cout << "catch any exception..." << endl; }
	return 0;
}