#include<iostream>
#include<thread>
#include<exception>
using namespace std;
/*
    1.Create a global instance of std::exception_ptr initialized to nullptr
    2.Inside the function that executes as a child thread, 
      wrap the 'throw' statement in try block, and have a corresponding
      catch-any block. Inside the catch-any block set the std::current_exception() 
      to the std::exception_ptr in step#1
    3.Inside the main thread, check if the global exception pointer is set.
    4.If yes, use std::rethrow_exception(exception_ptr p) to rethrow the 
      exception referenced by exception_ptr parameter.
*/
std::exception_ptr exPtr=nullptr;

void fun()
{
    try
    {
        cout <<"inside fun()" << endl;
        //...
        //raise an exception...
        throw std::runtime_error("Exception from fun...");
    }
    catch(...)
    {
        exPtr = std::current_exception();
    }
}

int main()
{
    thread th1(&fun);
    //...
    th1.join();
    if (exPtr != nullptr)
    {
        try
        {
            std::rethrow_exception(exPtr);
        }
        catch (const std::exception &x)
        {
            cout << "exception ..." << x.what() << endl;
        }
    }
    return 0;
}