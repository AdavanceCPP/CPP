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

//DELETER-1
auto deleter1 = [](DataA *p) ->void
{
    cout << "deleter1 execution started..." << endl;
    cout << "Handling Custom deletion for DataA type..." << endl;
    delete p;
    cout << "deleter1 execution completed..." << endl;
};


//------consumer code ------
int main()
{
    /*
        Providing custom delete handler for a unique_ptr instance, whose heap resource
        is being acquired thru a call to 'make_unique'.
    */

    unique_ptr<DataA, function<void(DataA*)>> ptr1 = make_unique<DataA>();
    ptr1.get_deleter() = deleter1;
    
    return 0;
}