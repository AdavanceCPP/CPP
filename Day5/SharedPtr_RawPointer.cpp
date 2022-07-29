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
	/*
		- Assigning a 'raw pointer' to a multiple shared object's would lead to
			dangling pointer issues.
		- Would result in an exception (double delete)
	*/
	CA *p = new(nothrow) CA;

    //A Bad idea
	shared_ptr<CA> ptr1(p);   
	
	shared_ptr<CA> ptr2(p);

	//check the use count of both shared_ptr objects
	cout << "ptr1 - use count:" << ptr1.use_count() << endl;
	cout << "ptr2 -use count: " << ptr2.use_count() << endl;

	return 0;
}