#include<iostream>
#include<optional>
using namespace std;

int main()
{
    cout <<"size of optional<char>:" << sizeof(optional<char>) << endl;
    cout <<"size of optional<int>:" << sizeof(optional<int>) << endl;
    cout <<"size of optional<double>:" << sizeof(optional<double>) << endl;
   
    return 0;
}