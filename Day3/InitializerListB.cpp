#include<iostream>
#include<initializer_list>
using namespace std;

class CA
{
private:
	initializer_list<int> arr;
public:
	CA(const initializer_list<int> &x):arr(x)
	{
		cout << "initializer list constructor" << endl;
	}

	void print()
	{
		for (auto &val : arr)
		{
			cout << val << ",";
		}
		cout << endl;
	}

	auto begin()
	{
		return arr.begin();
	}
	auto end()
	{
		return arr.end();
	}
};

int main()
{
	CA obj1{ 10,20,30,40,50,60,70,80 };
	//obj1.print();

	for(auto x: obj1)
	{
		cout << x <<",";
	}	
	return 0;
}