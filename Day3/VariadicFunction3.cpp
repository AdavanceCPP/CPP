#include<iostream>
#include<type_traits>
using namespace std;

/*
	- We can design a variadic function without an additional placeholder variable, 
	  avoiding:
	  	- recursion for parameter-pack unwinding,
		- Overloaded function to break recursion...
	 When we want the function to accept arbitary number of inputs of HOMOGENOUS kind.

*/

template<typename... PACK> void UnPack(PACK... Args)
{
	static_assert(sizeof...(Args) != 0, "Cannot call with NIL Args!");

    auto vals = {Args...};   // auto vals = initializer_list<int>{Args...};
	// initializer_list<int> vals = initializer_list<int>{10,20,30,40,50};
	
	cout << "size of pack" << vals.size() << endl;
	
	for (auto &x : vals) { cout << x << ","; }
}

int main()
{
	//UnPack();
    UnPack(10, 20, 30, 40, 50);
	return 0;
}