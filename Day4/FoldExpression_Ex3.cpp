#include<iostream>
using namespace std;

template<typename... Pack> void Process(Pack... Args)
{
    auto lm =[](auto& x){cout << x << endl;};  //C++14 -Generic lambda

    (lm(Args), ...);   //Fold over comma
    //(..., lm(Args));   //Fold over comma
}

int main()
{
    Process(10,20,30,"cpp",50.56f);
    return 0;
}