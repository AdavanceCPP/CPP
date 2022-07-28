#include<iostream>
#include<memory>
#include<functional>
using namespace std;
/*
    - Handling array of instances with unique_ptr 
*/
class Resource
{
    int a;
public:
    Resource(int x=0):a(x){cout <<"Resource default constructor" << endl;}
    void print() const {cout <<"Resource print, a:" << a << endl;}
    ~Resource(){cout <<"Resource Destructor" << endl;}
};

//consumer code...
int main()
{
    //Define a custom delete handler
    auto Arr_deleter =[](Resource* x)
    {
        cout <<"Custom delete handler execution started..." << endl;
        cout <<"custom business accomplised before de-allocation..." << endl;
        delete []x;
        cout <<"Custom delete handler execution completed..." << endl;
    };
    
    //Create an array of 5 Resource type instances...
    /*
       - The unique_ptr instance 'ptr1' constructed below, is actually set
         for the built-in default_delete handler, further every instance part
         of the array would only call the default constructor.

       - With 'make_unique' call there is no provision to provide custom 
         delete_handlers as a parameter.
    */ 
                            
    auto ptr1 = make_unique<Resource[]>(5);

    /*
        - There is a late realization, that an array of heap resources already
          owned by 'ptr1' must actually call the custom delete_handler and not
          the built-in default_delete handler, then what ?

          We try and make use of 'release()' function to take ownership of this
          heap memory, owned by 'ptr1' acquired thru make_unique helper function
          onto a new unique_ptr instance 'ptr2'.

          Note: std::move() would not work, thereby 'release()'
    */

    unique_ptr<Resource[],function<void(Resource*)>> ptr2(ptr1.release(),Arr_deleter);
    //unique_ptr<Resource[],function<void(Resource*)>> ptr2(move(ptr1),Arr_deleter);
    ptr2[0].print();
    ptr2[1].print();
    //etc...
    return 0;
}


