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
    Resource():a(0){cout <<"Resource default constructor" << endl;}
    Resource(int x):a(x){cout <<"Resource one arg. constructor" << endl;}
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
        delete [] x;
        cout <<"Custom delete handler execution completed..." << endl;
    };
    
    //Create an array of 5 Resource type instances...
    //De-allocation with custom 'delete' handler 
    /*
    unique_ptr<Resource,function<void(Resource*)>> ptr2(new Resource[4]{{10},{20}},Arr_deleter);
    
    (ptr2.get())[0].print();
    (ptr2.get())[1].print();
     */
    
    unique_ptr<Resource[],function<void(Resource*)>> ptr2(new Resource[4]{{10},{20}},Arr_deleter);
    
    ptr2[0].print();
    ptr2[1].print();

    return 0;
}


