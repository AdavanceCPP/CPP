#include<iostream>
using namespace std;

//lambda demo

int main()
{
    //define a lambda without a handle and invoke the same at
    //the point of definition itself.

    []()
    {
        cout <<"Lambda without a handle called.." << endl;
    }();

    cout <<"-------------" << endl;
    //Define a lambda with a handle
    auto lm = []()
    {
        cout <<"Lambda with a handle ..." <<endl;
    };

    //Invoke the lambda..
    lm();
    return 0;
}