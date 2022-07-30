#include<iostream>
#include<exception>
#include<string>
#include <valarray>
using namespace std;

exception_ptr fun()
{
    auto exp1 = make_exception_ptr(logic_error("logical error in fun"));
    auto exp2 = make_exception_ptr(runtime_error("run time error in fun"));
    //..
    //if(condition-1)
        //return exp1;
    //else
        return exp2;         
}

int main()
{
    exception_ptr exp;
    try
    {
        exp = fun();
        rethrow_exception(exp);
    }   
    catch(const exception &x)
    {
      cout <<"exception received in main..." << x.what() << endl; 
    }
      
    return 0;
}