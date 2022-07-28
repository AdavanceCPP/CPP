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

//Traditional CPP global function that takes ownership 
// of a heap resource thru a raw pointer.
void Some_Business(IData* p)
{
    cout <<"Some_Business execution started..." << endl;
    p->fun();
    //..other relevant businesses....
    //explicit de-allocation of heap resource inside the library
    delete p;
    cout <<"Some_Business execution completed..." << endl;
}
//------Modern CPP App. Developer / library consumer ------
int main()
{
    unique_ptr<IData> ptr;  
    ptr = make_unique<DataA>();
    
    //Transfer owner-ship of the HEAP resource to the library function
    /* The 'release()' function will transfer ownership to a raw_pointer */
    Some_Business(ptr.release());  //Now 'ptr' is nullptr
    //....
    ptr = make_unique<DataB>();
    //Transfer owner-ship of the HEAP resource to the library function
    Some_Business(ptr.release());
    return 0;
}