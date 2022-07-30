#include<iostream>
#include<type_traits>
#include<string>
using namespace std;

//A class suitable only for arithmetic types
template<typename T> class CA
{
	
	//..
public:
	CA(){ static_assert(is_arithmetic<T>::value, "Type must be arithmetic"); }
	//...
};

template<> class CA<char>
{
	//for char types only
};

int main()
{
	CA<int> obj1; //ok
	CA<char> obj2;  //ok

	CA<string> obj3;  //error
	return 0;
}