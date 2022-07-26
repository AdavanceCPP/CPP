#include<iostream>
using namespace std;

int main()
{
    int a=10,b=20;

    auto lm1 = [&]()
    {
        cout <<"inside lambda..." << endl;
        cout <<"a = " << a << endl;
        cout <<"b =" << b << endl;
    };

    cout <<"values of a and b in main before calling lambda function" << endl;
    cout <<"a = " << a << endl;
    cout <<"b =" << b << endl;
    cout <<"------------" << endl;
    lm1();
    cout <<"values of a and b in main after calling lambda function" << endl;
    cout <<"a = " << a << endl;
    cout <<"b =" << b << endl;

    return 0;
}