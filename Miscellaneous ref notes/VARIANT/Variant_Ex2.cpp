#include<iostream>
#include<variant>

using namespace std;



int main()
{
    variant<int,float,double> v1{56.12f};
    cout << v1.index() << endl;
    switch(v1.index())
    {
        case 0: cout << get<0>(v1) << endl;
        break;
        case 1: cout << get<1>(v1) << endl;
        break;
        case 2: cout << get<2>(v1) << endl;
    }
    return 0;
}