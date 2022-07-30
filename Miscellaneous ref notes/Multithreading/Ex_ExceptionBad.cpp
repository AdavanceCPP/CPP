#include<iostream>
#include<thread>
#include<exception>
using namespace std;

void fun()
{
    cout <<"inside fun()" << endl;
    //...
    //raise an exception...
    throw std::runtime_error("Exception from fun...");
}

int main()
{
    try
    {
        thread th1(&fun);
        //...
        th1.join();
    }
    catch(const std::exception &x)
    {
        cout <<"exception ..." << x.what() << endl;
    }
    return 0;
}