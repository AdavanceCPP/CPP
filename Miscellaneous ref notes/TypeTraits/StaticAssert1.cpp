#include<iostream>
#include<type_traits>
using namespace std;

template<typename T1> class CA
{
	static_assert(is_pod<T1>::value, "Template argument cannot be a class type");
	
private:
	T1 a, b;
};
class CB
{
public:
	CB(){ }
	~CB(){ }
};

void main()
{
	CA<char> obj1;
	//CA<CB> obj2;  //error
	
}
