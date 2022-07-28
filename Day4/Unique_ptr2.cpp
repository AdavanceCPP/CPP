#include<iostream>
#include<memory>
using namespace std;

class Resource
{
public:
    Resource(){cout <<"Resource default constructor" << endl;}
    ~Resource(){cout <<"Resource Destructor" << endl;}
    void fun(){cout <<"Resource fun called..." << endl;}
};

void GFunc(unique_ptr<Resource> ptr) // 'ptr' gets move constructed
{
    cout <<"GFunc execution started..." << endl;
    ptr->fun();
    cout <<"GFunc execution completed..." << endl;
}

int main()
{
    auto ptr1 = make_unique<Resource>();

    if(ptr1)         // if(ptr1.operator bool())
    {
        cout <<"ptr1 handle is valid..." << endl;
        ptr1->fun();
    }
    else
    {
        cout <<"ptr1 handle is not valid anymore..." << endl;
    }
    // Must be move constructed to transfer ownership
    GFunc(std::move(ptr1));
    
    if(ptr1)
    {
        cout <<"ptr1 handle is valid..." << endl;
        ptr1->fun();
    }
    else
    {
        cout <<"ptr1 handle is not valid anymore..." << endl;
    }
    
    return 0;
}


