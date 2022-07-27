#include<iostream>
using namespace std;

//A traditional C++ generic function

template<typename T1, typename T2> void Wrapper(T1& x, T2& y)
{
    cout <<"x=" << x << endl;
    cout <<"y=" << y << endl;
}

template<typename T1, typename T2> void Wrapper(T1& x, const T2& y)
{
    cout <<"x=" << x << endl;
    cout <<"y=" << y << endl;
}

template<typename T1, typename T2> void Wrapper(const T1& x, T2& y)
{
    cout <<"x=" << x << endl;
    cout <<"y=" << y << endl;
}

template<typename T1, typename T2> void Wrapper(const T1& x, const T2& y)
{
    cout <<"x=" << x << endl;
    cout <<"y=" << y << endl;
}
//***consumer code
int main()
{
    int a=10;
    float b=34.12f;
    Wrapper(a,b);
    Wrapper(100, 45.12f);
    Wrapper(a, 45.12f);
    Wrapper(100, b);
    return 0;
}