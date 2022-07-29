#include<iostream>
#include<memory>
using namespace std;
class CA
{
    private:
    int a,b;
public:
    CA():a(0),b(0) { cout << "CA default constructor called" << endl; }
    CA(int x):a(x),b(x) { cout << "CA one arg. constructor called" << endl; }
	CA(int x, int y):a(x),b(y) { cout << "CA two arg. constructor called" << endl; }
	~CA() { cout << "CA destructor called" << endl; }
	void print() { cout << "CA-print called, a:" << a <<",b:" << b << endl; }
};

int main() 
{
    //Approach - 1
    shared_ptr<CA[]> ptr1(new(nothrow) CA[5]);  //Every CA instance would implicitly call default constr.
     cout <<"------------" << endl;
    //Approach - 2
	//shared_ptr<CA> ptr2(new(nothrow) CA[5], default_delete<CA[]>());
   
    //Approach-3
     cout <<"------------" << endl;
     shared_ptr<CA[]> ptr3(new(nothrow) CA[3]{{10,20},{30},{}});
    return 0;
}

