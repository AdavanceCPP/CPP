#include <iostream>
#include <memory>
#include<functional>
using namespace std;
//An example on 'get_deleter' member function
class DataA
{
public:
    DataA() { cout << "DataA constructor" << endl; }
    void fun() { cout << "DataA fun" << endl; }
    ~DataA() { cout << "DataA destructor" << endl; }
};

//Three different types of deleter's
//DELETER-1
auto deleter1 = [](DataA *p) 
{
    cout << "deleter1 execution started..." << endl;
    cout << "Handling Custom deletion for DataA type..." << endl;
    delete p;
    cout << "deleter1 execution completed..." << endl;
};
//DELETER-2
auto deleter2 = [](DataA *p) 
{
    cout << "deleter2 execution started..." << endl;
    cout << "Handling Custom deletion for DataA type..." << endl;
    delete p;
    cout << "deleter2 execution completed..." << endl;
};

//DELETER-3
auto deleter3 = [](DataA *p) 
{
    cout << "deleter3 execution started..." << endl;
    cout << "Handling Custom deletion for DataA type..." << endl;
    delete[] p;
    cout << "deleter3 execution completed..." << endl;
};

//------consumer code ------
int main()
{

    unique_ptr<DataA, function<void(DataA*)>> ptr1 = make_unique<DataA>();
    
    bool condition1 =false, condition2 = true;

    if(condition1)
    {
        ptr1.get_deleter() = deleter1;
    }
    else if(condition2)
    {
        ptr1.get_deleter() = deleter2;
    }
    
    //some other business...
    //..
    cout <<"*******************" << endl;
    unique_ptr<DataA[], function<void(DataA*)>> ptr2 = make_unique<DataA[]>(5);
    ptr2.get_deleter() = deleter3;
    cout <<"*******************" << endl;
    
    return 0;
}