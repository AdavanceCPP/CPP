#include<iostream>
using namespace std;

int main()
{
    //define a lambda
    auto lm1 = [](int x) ->void
    {
        cout <<"Lambda with handle lm1 called, x=" << x << endl;
    };

    auto lm2 = [](int x) ->int
    {
        cout <<"Lambda with handle lm2 called," << endl;
        return x+100;
    };

    lm1(100);
    cout <<"-------------" << endl;
    auto result = lm2(200);
    cout <<"result =" << result << endl;
    return 0;
}