#include<iostream>
#include<typeinfo>
using namespace std;

//an example 'decltype' type-inference keyword

int main()
{
    auto a = 100;
    auto b = 45.21f;

    //Declare a variable called 'val1' whose type has to be the same type as element 'a'
    decltype(a) val1{};
    cout <<"address of a =" << &a <<", its value =" << a << endl;
    cout <<"address of val1 =" << &val1 <<", its value =" << val1 << endl;
    cout <<"--------------------" << endl;
    //Declare a variable whose type has to be result of the computed value of 'a' and 'b'
    decltype(a*b) val2;
    val2 = a+b;
    cout <<"data type of val2 =" << typeid(val2).name() << "its value =" << val2 << endl;
    cout <<"--------------------" << endl;
    //We can also declare reference types or aliases with decltype....
    auto z = 500;
    decltype((a)) ref1 = z;    // decltype(&(int)) ref1 = z;    ==> int& ref1 = z;
    cout <<"address of z =" << &z <<", its value =" << z << endl;
    cout <<"address of ref1 =" << &ref1 <<", its value =" << ref1 << endl;
    cout <<"--------------------" << endl;
    //Also the extended qualifiers are carried forward...
    const int num1 = 400;
    //decltype(num1) num2;      //error, proves 'const' is being carried forward
    decltype(num1) num2 = 600;  //ok
    //num2=800;   //error, cannot modify a const variable
    return 0;
}