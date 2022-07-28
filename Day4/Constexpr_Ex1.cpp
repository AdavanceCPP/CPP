#include<iostream>
using namespace std;

constexpr int Sum(int x, int y)
{
    //cout <<"sum called" << endl;
    //int z{100};
    return x+y;
}

//***consumer code***********
int main()
{
    //const int x = Sum(10,20);
    constexpr int x = Sum(10,20);
    cout <<"x=" << x << endl;
    cout <<"---------------" << endl;
    int a=30,b=30;
    cout << Sum(a,b) << endl;
   
    return 0;
}