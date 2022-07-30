#include<iostream>
#include<type_traits>
using namespace std;

template<typename T> class CA
{
	static_assert(has_virtual_destructor<T>::value, "Class CA does not have virtual destructor");
public:
	CA(){ }
	~CA(){}
};

template<typename T> class CB
{
	static_assert(is_class<T>::value, "Must instantiate class types only");
public:
	CB(){ }
	~CB(){ };
};

class CC
{
public:
	CC(){}
};

void main()
{
	//CA<int> obj1;
	//CB<int> obj2;
	//CB<CC> obj3;
	
}