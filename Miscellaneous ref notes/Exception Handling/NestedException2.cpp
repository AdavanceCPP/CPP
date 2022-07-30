#include<iostream>
#include<string>
#include<exception>
#include <valarray>
using namespace std;

void AllExceptions(const exception &x, int level=0)
{
    cout << ",level:" << level <<",AllExceptions..." << x.what()  << endl;
    try
    {
        rethrow_if_nested(x);
    }
    catch(const exception &x)
    {
        AllExceptions(x,level+1);
    }
    catch(...){}
}

void fun3()
{
   try
    {
       throw 10;
    }
    catch(...)
    {
        throw_with_nested(runtime_error("fun3..."));
    } 
}

void fun2()
{
   try
    {
        fun3();
    }
    catch(...)
    {
        throw_with_nested(runtime_error("fun2..."));
    }
} 

void fun1()
{
    try
    {
        fun2();
    }
    catch(...)
    {
        throw_with_nested(runtime_error("fun1..."));
    }
}

int main()
{
    try
    {
        fun1();
    }
    catch(const exception &x)
    {
        AllExceptions(x);
    }
    return 0;
}