#include<iostream>
#include<tuple>
#include<string>
using namespace std;

int main()
{
    auto tup = make_tuple("apply function",100, 45.12f);
    //process the values in tuple

    auto lm1 = [] (auto& x){cout << x <<",";};

    auto lm2 =[&](auto... args)
    {
        //(cout << ... << args);
        (lm1(args),...);
    };
    std::apply(lm2,tup);  //C++17 onwards to process tuple
    
    return 0;
}