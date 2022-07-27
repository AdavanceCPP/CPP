#include<iostream>
#include<initializer_list>
using namespace std;

class CA
{
private:
	int arr[6];
public:
	CA(const initializer_list<int> &x) 
	{
		int i = 0;
		if (x.size() <= 6)
		{
			for (auto &val : x)
			{
				arr[i] = val;
				++i;
			}
		}
		else
			cout << "Excess parameters, initialization failed" << endl;
	}

	void print()
	{
		for (auto &val : arr)
		{
			cout << val << ",";
		}
		cout << endl;
	}
};

int main()
{
	CA obj1{ 10,20,30,40,50,60 };  // CA obj1(initializer_list<int>{10,20,30,40,50,60} );
	obj1.print();

	return 0;
}