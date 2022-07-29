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
    if (ptr1)
		cout << "shared_count :" << ptr1.use_count() << endl;
        
	ptr1.reset();
	if (ptr1)
		cout << "shared_count :" << ptr1.use_count() << endl;
	else
		cout << "sharing no object  :" <<  endl;
	return 0;
}

