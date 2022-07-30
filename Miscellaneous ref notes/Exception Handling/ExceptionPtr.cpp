#include<iostream>
#include<exception>
#include<string>
#include<array>
using namespace std;

void ExceptionHandler(exception_ptr x)
{
    try
    {
        if(x)
        rethrow_exception(x);
    }
    catch(const exception &x)
    {
        cout << "Exception, " << x.what() << endl;
    }
}

int main()
{
    exception_ptr exp;
    try
    {
        //throw runtime_error(" main ");
        
        //string s;
        //cout << s.at(1) << endl;
    
        throw bad_alloc();
    }
    
    catch(...)
    {
        exp = current_exception();
        cout << (exp.__cxa_exception_type())->name() << endl;
    }
    
    ExceptionHandler(exp);

    return 0;
}