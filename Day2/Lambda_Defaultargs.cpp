#include<iostream>
using namespace std;

/*
    In C++14, lambda functions can take default arguments.
*/

int main()
{
    auto lm = [](int x=1, int y=2)
    {
        cout <<"lambda lm called, x =" << x<<", y=" << y << endl;
    };

    lm();
    lm(100);
    lm(20,30);
    return 0;
}