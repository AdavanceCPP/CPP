#include<iostream>
using namespace std;

//C++14 - Lambda arbitrary capture...
int fun(int x)
{
    return x*10;
}

int main()
{
    int a=100;
    //C++11 arrangment
    auto lm1 =[&a]()
    {
        int z = a*a;
        cout << z << endl;
    };

    //C++14 arrangement [Arbitrary capture]
    auto lm2 =[z = a*a]()
    {
        cout << z << endl;
    };
    //   [z = a*a]   ====>  auto z = a*a;
    cout <<"----------------------" << endl;
    auto lm3 =[result = fun(100)]()
    {
        cout << result << endl;
    };

    //invoke the lambdas....
    lm1();
    lm2();
    lm3();
    return 0;
}