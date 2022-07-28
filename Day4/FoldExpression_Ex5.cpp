#include<iostream>
using namespace std;

//variadic function with fold expression...
template<typename... Args> void VariadicFun1(Args... Data)
{
	//(cout << ... << std::forward<Args>(Data));
	(cout << ... <<  Data);
	cout << endl;
}

template<typename... Args> void VariadicFun2(Args... Data)
{
	auto delimiter = [](const auto& v)
	{
		cout << v << ",";
	};

	//(..., delimiter(std::forward<Args>(Data)));
	(..., delimiter(Data));
	cout << endl;
}

//***consumer code***
int main()
{
	VariadicFun1(56, 12, 56, 87.90, 'c');
	//cout << endl <<"------------" << endl;
	VariadicFun2(56, 12, 56, 87.90, 'c');
	return 0;
}