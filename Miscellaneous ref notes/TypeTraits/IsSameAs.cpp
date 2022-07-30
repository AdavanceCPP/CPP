#include<iostream>
#include<vector>
#include<type_traits>
using namespace std;

template<typename T> void Add(T x)
{
    vector<bool> v1;
    //No matter what input 'Add' recieves, only 'bool' types must be pushed onto the vector,
    //all others ignored.
    if(is_same<bool, T>::value)
    {
        v1.push_back(x);
    }
    else
    {
        cout <<"Not bool, ignoring..." << x << endl;
    }
}

int main()
{
    Add(10);
    Add(true);
    Add(300);
    Add(false);
    return 0;
}