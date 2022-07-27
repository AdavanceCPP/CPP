#include<iostream>
#include<typeinfo>
using namespace std;

template<typename T> void fun(T x=10)
{
    cout <<"data type of x is - " << typeid(T).name() <<", its value=" << x <<endl;
}

//***consumer code
int main()
{
    fun();
    fun(12.43f);
    fun(67.1223);
    //....
    return 0;
}