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
	shared_ptr<CA> ptr1(new CA());
	
	shared_ptr<CA> ptr2(ptr1);

	cout << "objects shared" << ptr1.use_count() << endl;

	weak_ptr<CA> wk1 = ptr1; //Brings about an association between weak_ptr and shared_ptr instance

	//A call to use 'use_count()' function of weak_ptr will only yeild strong_count.
	cout << "objects shared after weak reference" << wk1.use_count() << endl;

	auto ptr3 = wk1.lock();  //this 'lock' function returns a shared_ptr instance

	ptr1->print();
	ptr2->print();
	ptr3->print();
	
	cout << "shared count, after acquiring lock:" << ptr1.use_count() << endl;
	cout << "weak count after providing lock:" << wk1.use_count() << endl;

	return 0;
}

