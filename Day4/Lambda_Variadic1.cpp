#include<iostream>
using namespace std;
/*
	- C++11 / 14 approach
*/
template<typename T> void varPrint(T data)
{
	cout << data <<endl;
}

template<typename T, typename... PACK> void varPrint(T data, PACK ...Args)
{
	cout << data <<",";
	varPrint(Args...);
}

int main()
{
    // An use-case for type-inference keyword 'auto'
	// for defining a lambda handle, else would be challenge
	auto varLambda = [](auto... Args)
	{
		varPrint(Args...);
	};

    varLambda(100,200,45.12f, 89.21, 'a', "variadic");
	return 0;
}