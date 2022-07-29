#include<iostream>
#include<memory>
using namespace std;

/*
    It is not a good idea to design function with RVALUE reference type of 
    shared_ptr.

    It is ok for a function to take LVALUE reference type as long as the
    function plans to do a swap or a reset on the shared_ptr handle.

    Else, let the function take shared_ptr as formal parameter by value.
*/

void fun(shared_ptr<int>& p)
{
    cout <<"inside fun()" << p.use_count() << endl;
    cout << *p << endl;
    
    p.reset();
}

int main()
{
    shared_ptr<int> ptr = make_shared<int>(100);
    if(ptr)   // if(ptr.operator bool())
         cout <<"use count before fun call:" << ptr.use_count() << endl;

    fun(ptr);

    if(ptr)
        cout <<"use count after fun call:" << ptr.use_count() << endl;
    else    
        cout <<"ptr is nullptr..." << endl;         
    return 0;
}
