#include<iostream>
#include<memory>
using namespace std;

class Resource
{
public:
    Resource(){cout <<"Resource default constructor" << endl;}
    ~Resource(){cout <<"Resource Destructor" << endl;}
};

/*
    - 'unique_ptr' is an exclusive owner of an heap instance. it's
       instances cannot be shared, that is it cannot be copy constructed.
    - It is a move only type, doing so will transfer ownership.
*/

void fun(unique_ptr<Resource> ptr) // 'ptr' gets move constructed
{
    cout <<"fun execution started..." << endl;
    //...
    cout <<"fun execution completed..." << endl;
}


int main()
{
    //...1, not recommended, too stretched syntax, 'unique_ptr' is repititive
    unique_ptr<Resource> ptr1 = unique_ptr<Resource>(new(nothrow) Resource());

    cout <<"------------------" << endl;
    //...2, not recommended, not a good idea to explicitly use 'new' 
    unique_ptr<Resource> ptr2(new(nothrow)(Resource));


    cout <<"------------------" << endl;
    //...3, OK - no explicit 'new' nor 'delete' operator call.
    unique_ptr<Resource> ptr3 = make_unique<Resource>();


    cout <<"------------------" << endl;
    //...4, OR
    auto ptr4 = make_unique<Resource>();


    //Also 'make_unique' helper function would be handy when calling a function
    //that take's unique_ptr as a parameter. For eg:-
    cout <<"------------------" << endl;
    //...1, not a good-idea
    fun(unique_ptr<Resource>(new(nothrow) Resource()));  //fun(RVALUE)

    cout <<"------------------" << endl;
    //...2, a better approach - make_unique helper
    fun(make_unique<Resource>());   //fun(RVALUE)
    cout <<"------------------" << endl;
    fun(std::move(ptr1));   //fun(std::move(LVALUE))
    cout<<"controlled returned back from fun..." << endl;
    return 0;
}


