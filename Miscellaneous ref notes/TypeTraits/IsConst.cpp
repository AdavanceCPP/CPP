#include<iostream>
#include<type_traits>
using namespace std;

template<typename T> void fun()
{
	bool result;
	result = is_const<T>::value;
	if (result) 
		cout << "it is a const" << endl;
	else
		cout << "it is not a const" << endl;
}

int main()
{
	fun<int>();
	fun<const int>();
	return 0;
}