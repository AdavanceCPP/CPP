// ModernSmartPointers.cpp : Defines the entry point for the console application.
//

#include<iostream>
#include<memory>
using namespace std;
class CA
{
public:
	CA() { cout << "CA constructor called" << endl; }
	~CA() { cout << "CA destructor called" << endl; }
	void print() { cout << "CA-print called:" << this << endl; }
};


int main()
{
	shared_ptr<CA> ptr1 = make_shared<CA>();
	weak_ptr<CA> wk1(ptr1);

	//ptr1.reset();  //destroy the resource to the handle 'ptr1'
	
	if (auto ptr2 = wk1.lock())  // use 'operator bool' as against 'expired' function
	{
		cout << "Successfully accquired a lock on 'wk1':" << endl;
	}
	else
	{
		cout << "Failed to accquire a lock on 'wk1':" << endl;
	}

	return 0;
}

