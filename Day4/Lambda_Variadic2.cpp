#include<iostream>
using namespace std;

//C++14 - Variadic lambdas.
int main()
{
    //Variadic lambda that handles arbitrary number of homogenous inputs.
	auto varLambda = [](auto... Args)
	{
		auto vals = {Args...};
        for(auto x:vals){cout << x <<",";}
        cout << endl;
	};

    varLambda(100,200,300,400,500);
	return 0;
}