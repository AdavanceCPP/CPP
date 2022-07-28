#include<iostream>
#include<memory>
using namespace std;

// POLYMORPHIC CLASS FAMILY
class IData
{
public:
    virtual void fun() = 0;
    virtual ~IData() {}
};
class DataA : public IData
{
public:
    DataA(){cout <<"DataA constructor" << endl;}
    void fun() override { cout << "DataA fun" << endl; }
    ~DataA() { cout << "DataA destructor" << endl; }
};

class DataB : public IData
{
public:
    DataB(){cout <<"DataB constructor" << endl;}
    void fun() override { cout << "DataB fun" << endl; }
    ~DataB() { cout << "DataB destructor" << endl; }
};

//Traditional CPP function that has a handle to a heap resource 
// accquired in the client code, not responsible for deallocating
// the heap resource.
void Some_Business(IData* p)
{
    cout <<"Some_Business execution started..." << endl;
    p->fun();
    //..other relevant businesses....
    cout <<"Some_Business execution completed..." << endl;
}

//------Modern CPP App. Developer / library consumer ------
int main()
{
    unique_ptr<IData> ptr;  
    //...
    ptr = make_unique<DataA>();
    //Extract address of the HEAP resource and send it to the library function
   
    Some_Business(ptr.get());
    cout << "--------------" << endl;
    
    //....
    ptr = make_unique<DataB>();
    //..
    //Extract address of the HEAP resource and send it to the library function
    Some_Business(ptr.get());
    return 0;
}