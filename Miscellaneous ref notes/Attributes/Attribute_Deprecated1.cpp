#include<iostream>
#include<string>
using namespace std;


[[deprecated ("Use 'fun(std::string)' instead")]] void fun(const char* p) {  }

void fun(std::string x) { cout << "fun(std::string x) called" << endl; }

//-------------------------
[[deprecated("Use Compute(int,int) instead")]] void Calculate(int a, int b) {}

void Compute(int a, int b) { cout << "Compute(int a, int b) called.." << endl; }
//------------------------
//Consumer is not provided with alternative...
[[deprecated]] void Process();

//****consumer code *****
int main()
{
	//fun("asdf");
	fun(std::string("asdf"));

	//Calculate(10, 20);
	Compute(10, 20);

	Process();
	return 0;
} 

void Process() {}