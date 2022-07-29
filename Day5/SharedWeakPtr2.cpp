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
	
	ptr1.reset();  //destroy the resource to the handle 'ptr1'
	//Now acquire a 'lock' from the weak_ptr
	if (!wk1.expired())
	{
		auto ptr2 = wk1.lock();
		cout << "Successfully accquired a lock on 'wk1':" << endl;
		cout <<"strong count:" << ptr1.use_count() << endl;
		ptr1->print();
	}
	else
	{
		cout << "Failed to accquire a lock on 'wk1':" << endl;
	}
	
	return 0;
}

