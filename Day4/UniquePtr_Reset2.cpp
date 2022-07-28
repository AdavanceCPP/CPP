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


//------Modern CPP App. Developer / library consumer ------
int main()
{
    unique_ptr<IData> ptr1 = make_unique<DataA>();  
    ptr1->fun();
    cout <<"--------------------" <<endl;
    unique_ptr<IData> ptr2 = make_unique<DataB>();  
    ptr2->fun();
    cout <<"Let us clear or de-allocate the earlier allocations..." << endl;

    ptr1.reset();  //MANUAL DE-ALLOCATION, never wait for 'ptr1' to die
    ptr2.reset();  //MANUAL DE-ALLOCATION, never wait for 'ptr2' to die

    cout <<"*****FRESH ALLOCATIONS ARE BEING MADE***********" << endl;
    unique_ptr<IData> ptr3 = make_unique<DataA>();  
    ptr3->fun();
    cout <<"--------------------" <<endl;
    unique_ptr<IData> ptr4 = make_unique<DataB>();  
    ptr4->fun();
    
    return 0;
}