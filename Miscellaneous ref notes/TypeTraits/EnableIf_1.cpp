#include<iostream>
#include<type_traits>
using namespace std;

/* 
 SFINAE :- Substitution Failure Is Not An Error, 
             A constraint implemented on template types

	template<bool Test, class T = void> struct enable_if {};

	template<class T> struct enable_if<true, T>
	{
	  typedef T type;
	};
*/

//A generic function should only support Integral types
template<typename T, typename = typename enable_if<is_arithmetic<T>::value, T>::type>
void Add(T x, T y)
{
	cout << "sum = " << x + y << endl;
}

int main()
{
	Add(10, 20);
	Add('a', 't');
	return 0;
}
