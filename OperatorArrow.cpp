#include<iostream>
using namespace std;
//programmer-1
class CA
{
private:
  //..
public:
  void fun1(){cout <<"CA fun1 called" << endl;}  
  void fun2(){cout <<"CA fun2 called" << endl;} 
  void fun3(){cout <<"CA fun3 called" << endl;}   
};

//programmer-2
//Wrapper class for CA
class CB
{
private:
    CA* p;
public:
    CB()
    {
        p = new(nothrow) CA;
    }
    ~CB() { delete p; }  
    // void fun1()
    // {
    //     p->fun1();
    // }  
    CA* operator ->()
    {
        return p;
    }
};

//programmer-3

int main()
{
    CB obj1;
    //obj1.fun1();
    //obj1.fun2();
    obj1->fun1();
    obj1->fun2();
    obj1->fun3();
    return 0;
}
