#include<iostream>
#include<type_traits>
using namespace std;

template<typename T> void Add(const T a, const T b)
{
	static_assert(is_pod<T>::value, "Input parameters must be POD types");
	T c;
	//c = a + b;
	//cout << "sum is " << c << endl;
}
class CA
{
public:
	CA(){}
};
void main()
{
	Add(10, 20);
	CA obj1, obj2;
	Add(obj1,obj2);
}