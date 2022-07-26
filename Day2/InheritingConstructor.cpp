#include<iostream>
using namespace std;

/*
    - Now in modern C++11, we can also inherit constructors of the 
      base class onto the derived class.
*/

class Base
{
public:
    Base(){cout <<"Base default constructor..." << endl;}
    Base(int x){cout <<"Base one arg. constructor..." << endl;}
    Base(int x, int y){cout <<"Base two arg. constructor..." << endl;}
};

class Derived:public Base
{
public:
    using Base::Base;
};

//**consumer code***
int main()
{
    Derived obj1;
    //Derived obj2(100);
    //Derived obj3(10,20);
    return 0;
}