#include<iostream>
using namespace std;

class Base   //POLYMORPHIC base class
{
public:
  virtual void fun1(int x){cout <<"Base::fun1(int x) called" << endl;}
  virtual void fun2(int x){cout <<"Base::fun2(int x) called" << endl;}
};  

class Derived1:public Base   //POLYMORPHIC derived class
{
public:
  void fun1(int x) override
  {cout <<"Derived1::fun1(int x) called" << endl; }

  void fun2(int x) override
  { 
    cout <<"Derived1::fun2(int x) called" << endl;
  }
};

//Any attempt to further derive from 'Derived2' must be stopped.
class Derived2 final :public Base
{
public:  
  void fun1(int x) override
  {cout <<"Derived2::fun1(int x) called" << endl; }
  void fun2(int x) override
  {cout <<"Derived2::fun2(int x) called" << endl; }
};

class Derived3:public Derived2
{};

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