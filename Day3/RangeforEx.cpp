#include<iostream>
#include<list>
#include<algorithm>
using namespace std;

//An example on range-for modern construct in C++11.
//Designed to work on a collection or a range of values, that have a definite starting
//address and ending address.

int main()
{
    list<int> ls1 ={10,20,30,40,50,60,79};   
    list<char> ls2 ={'a','b','c','d','e'};   
/*
    //C++14- Generic lambda
    auto Generic_Lambda =[](auto x)
    {
        cout << x <<",";
    };

    for_each(ls1.begin(),ls1.end(),Generic_Lambda);
    cout << endl;
    for_each(ls2.begin(), ls2.end(), Generic_Lambda);
*/

    for(auto x:ls1)
    {
        cout <<x <<",";
    }
    cout << endl;
    for(auto x:ls2)
    {
        cout << x <<",";
    }
  
    return 0;
}