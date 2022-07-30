#include<iostream>
#include<variant>

using namespace std;

int main()
{
    variant<int,float,double> v1{56.12f};
    cout << v1.index() << endl;
    cout <<"-------------------" << endl;
    cout << boolalpha;
    cout << "holds_alternative<int>:" << holds_alternative<int>(v1) <<endl;
    cout << "holds_alternative<float>:" << holds_alternative<float>(v1) <<endl;
    cout << "holds_alternative<double>:" << holds_alternative<double>(v1) <<endl;
    //cout << "holds_alternative<char>:" << holds_alternative<char>(v1) <<endl;
    return 0;
}