#include<iostream>
#include<memory>
using namespace std;
/*
    - Handling array of instances with unique_ptr
*/
class Resource
{
    int a;
public:
    Resource():a(0){cout <<"Resource default constructor" << endl;}
    Resource(int x):a(x){cout <<"Resource one arg. constructor" << endl;}
    void print() const {cout <<"Resource print, a:" << a << endl;}
    ~Resource(){cout <<"Resource Destructor" << endl;}
};

//consumer code...
int main()
{
    //Create an array of 5 Resource type instances...
    //De-allocation with pre-defined 'default_delete' handler
    unique_ptr<Resource[]> ptr1 = make_unique<Resource[]>(5);


    ptr1[0].print();
    ptr1[1].print();
    
    //etc...
    cout<<"--------------" << endl;
    //unique_ptr<Resource[]> ptr2 = unique_ptr<Resource[]>(new Resource[4]{ {10},{200},{300},{500} } );
    unique_ptr<Resource[]> ptr2 (new Resource[4]{ {},{200},{},{500} } );
    ptr2[0].print();
    ptr2[1].print();
    ptr2[2].print();
    //...
    return 0;
}


