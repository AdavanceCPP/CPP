#include<iostream>
using namespace std;

namespace [[deprecated("Use SPACE_B instead")]] SPACE_A
{
	class CA {};
	void fun1() {  }
	void fun2(){ }
}

namespace SPACE_B
{
	class CA {};
	void fun1() {  }
	void fun2() { }
}
//***consumer code*****

int main()
{
	using namespace SPACE_A;
	CA obj1;
	fun1();
	fun2();
	return 0;
}