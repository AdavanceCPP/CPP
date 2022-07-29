#include<iostream>
#include<memory>
using namespace std;
class CA
{
    private:
    int a;
public:
	CA(int x=0):a(x) { cout << "CA constructor called" << endl; }
	~CA() { cout << "CA destructor called" << endl; }
	void print() { cout << "CA-print called:" << a << endl; }
};


int main() 
{
	shared_ptr<CA> ptr1 = make_shared<CA>(100);
    shared_ptr<CA> ptr2;

    cout <<"------Before assignment : ------" << endl;
    if(ptr1)
        cout <<"ptr1 use count:" << ptr1.use_count() << endl;
    else
        cout <<"ptr1 does not point to any valid heap resource..." << endl;    
            
    if(ptr2)
        cout <<"ptr2 use count:" << ptr2.use_count() << endl;
    else
        cout <<"ptr2 does not point to any valid heap resource..." << endl;        
    
    if(ptr1)
    {    
        ptr1->print();
    }
    else
    {
        cout <<"ptr1 handle is invalid" << endl;
    }
    cout <<"--------------" << endl;
    if(ptr2)
    {    
        ptr2->print();
    }
    else
    {
        cout <<"ptr2 handle is invalid" << endl;
    }
    //Assignment of shared_ptr instances...
    ptr2=ptr1;

    cout <<"----after assignment : -----" << endl;
    cout <<"ptr1 use count:" << ptr1.use_count() << endl;
    cout <<"ptr2 use count:" << ptr2.use_count() << endl;
    
    if(ptr1)
    {    
        ptr1->print();
    }
    else
    {
        cout <<"ptr1 handle is invalid" << endl;
    }
    cout <<"--------------" << endl;
    if(ptr2)
    {    
        ptr2->print();
    }
     else
    {
        cout <<"ptr2 handle is invalid" << endl;
    }
    
	return 0;
}

