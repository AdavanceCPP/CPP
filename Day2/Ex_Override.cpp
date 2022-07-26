#include<iostream>
using namespace std;

class Base   //POLYMORPHIC base class
{
public:
  virtual void fun1(int x){cout <<"Base::fun1(int x) called" << endl;}
  virtual void fun2(int x){cout <<"Base::fun2(int x) called" << endl;}
};  
/*
  Modern C++ guideline for polymorphic derived classes..
  For every over-ridden member function being defined in the derived class,
  tag the same with 'override' keyword. By doing so the compiler would do
  a strict signature match, any in-consistency it would flag-off 
  compile-time error.
*/
class Derived1:public Base   //POLYMORPHIC derived class
{
public:
  void fun1(int x) override
  {cout <<"Derived1::fun1(int x) called" << endl; }

 
  //void fun2(float x) override
  void fun2(int x) override
  { 
    cout <<"Derived1::fun2(float x) called" << endl;
  }
  
};

class Derived2:public Base
{
public:  
  void fun1(int x) override
  {cout <<"Derived2::fun1(int x) called" << endl; }
  void fun2(int x) override
  {cout <<"Derived2::fun2(int x) called" << endl; }
};

//***consumer code ****
void Process(Base* p)
{
    p->fun1(100);
    p->fun2(200);
    //...
    delete p;
}
int main()
{
    //Base* p = new(nothrow) Base;
    //Base* p = new(nothrow) Derived2;
    Base* p = new(nothrow) Derived1;
    Process(p);
    return 0;
}