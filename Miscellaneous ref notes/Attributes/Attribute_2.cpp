#include<iostream>
using namespace std;

void fun(int x) noexcept;

int main()
{
	fun(3);
	return 0;
}

void fun(int x) noexcept
{
	switch (x)
	{
	case 1:cout << "One_specific Business..." << endl;
		break;
	case 2: cout << "Two_specific Business..." << endl;
		break;
	case 3:
		[[fallthrough]];
	case 4:cout << "3 & 4 common business..." << endl;
		break;
	case 5:cout << "Five_specific Business..." << endl;
		break;
	default:cout << "Invalid value" << endl;
	}
}