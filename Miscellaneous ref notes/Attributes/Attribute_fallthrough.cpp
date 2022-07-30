#include<iostream>
using namespace std;

void fun(int x) noexcept;

int main()
{
	fun(5);
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
	case 4:
	case 5:
	case 6:cout << "3 till 5 common business..." << endl;
		break;
	case 7:cout << "7's specific Business..." << endl;
		break;
	default:cout << "Invalid value" << endl;
	}
}