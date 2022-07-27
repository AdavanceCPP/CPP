#include<iostream>
using namespace std;

// - C++11/14 variadic function.

auto SumAll()
{ 
	/* function to break recursion when there are no parameters in the pack */ 
	return 0;
}

template<typename T, typename... Args> auto SumAll(T x, Args...Data)
{
	return x + SumAll(Data...);
	// value_in_place_holder + Values to be expanded from the PARAMETER_PACK
}

// - C++17 : Fold Expressions

template<typename... Args> auto SumVal(Args... Data)
{
	return (Data + ...);
	// first_value_in_Data + The Remaining values in Data
}


//consumer code
int main()
{
	//cout << SumAll(10, 20, 30, 40, 50) << endl;
	cout << SumVal(10, 20, 30.23f, 40.90, 50) << endl;
	return 0;
}