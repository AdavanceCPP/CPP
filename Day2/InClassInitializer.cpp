#include<iostream>
using namespace std;
/* In class initializers, applicable only for non-static data members of the class  */
class CA
{
private:
	int a{};
	int b{ 20 };
	float c = 12.34f;
	int sum = a + b;
	double val = compute();
public: 

	//The compiler would induce a default constructor on our behalf, and consider
	// the values provided in the class declaration.

	// CA():a(0),b(20),c(12.34f),sum(a+b), val(compute())
	// {

	// }
	
	double compute()
	{
		return c * 45.56;
	}
	void print()
	{
		cout << "a =" << a << endl;
		cout << "b =" << b << endl;
		cout << "c =" << c << endl;
		cout << "sum =" << sum << endl;
		cout << "val =" << val << endl;
	}
};
//------------------
int main()
{
	CA obj1;
	obj1.print();
	return 0;
}