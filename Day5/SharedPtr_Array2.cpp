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

//---custom deleter function
auto MyDeleter =[](CA* x)
{
    cout <<"Custom deleter invoked..." << endl;
    cout <<"Critical business before de-allocation completed..." << endl;
    delete []x;
    cout <<"De-allocated..." << endl;
    cout <<"------------" << endl;
};

int main() 
{
    //Approach - 1 - uses default_delete
    shared_ptr<CA[]> ptr1(new(nothrow) CA[5]);  
    cout <<"------------" << endl;
    //The helper function 'make_shared' is not helpful for creating an array of instances
    //shared_ptr<CA[]> ptr1 = make_shared<CA[]>(5);

    cout <<"------------" << endl;
    //Approach - 2 - uses custom deleter
	shared_ptr<CA> ptr2(new(nothrow) CA[5], MyDeleter);
    
    cout <<"------------" << endl;
    //Approach - 3, implicit invocation to parameterized constructors, for each instance of the array
    shared_ptr<CA> ptr3(new(nothrow) CA[3]{{10,20},{30},{}}, MyDeleter);
    cout <<"------------" << endl;
    return 0;
}

