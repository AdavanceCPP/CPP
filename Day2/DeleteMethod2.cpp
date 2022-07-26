#include<iostream>
using namespace std;

//The 'delete' keyword can be used to dis-able certain template instantiations 
//as well.

template<typename T> void Add(T a, T b)
{
    cout <<"sum=" << a+b << endl;
}

//specialize the above function for CHAR type, and dis-able the same using 'delete'
template<> void Add(char,char)=delete;

//***consumer code************
int main()
{
    Add(100,200);
    Add(45.12f, 87.21f);
    Add(98.21, 67.46);
    //***************************
    Add('r','w');
    return 0;
}