#include<iostream>
#include<type_traits>
using namespace std;

namespace ONE
{
	static_assert(sizeof(void *) == 4, "Not 32 bit environment"); //evaluation immediately
}

void main()
{

}