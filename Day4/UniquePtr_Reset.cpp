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

//Traditional CPP factory method, return's a raw pointer.
template <typename T> class Factory
{
public:
    static T* GetData()
    {
        return new T();
    }
};
//------Modern CPP App. Developer / library consumer ------
int main()
{
    unique_ptr<IData> ptr;  
    /*
      'ptr' handle will automatically de-allocate the heap instance
      that was allocated at the library end.
    */
    ptr.reset(Factory<DataA>::GetData());
    ptr->fun();
    //....
    ptr.reset(Factory<DataB>::GetData());
    ptr->fun();
    //....
    cout <<"Main exiting..." << endl;
    return 0;
}