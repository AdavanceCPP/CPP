#include<iostream>
#include<vector>
#include<list>
#include<algorithm>
#include<initializer_list>
using namespace std;
class CA
{
private:
	vector<int> v1;
public:
	CA(const initializer_list<int> &v) :v1(v) { }

	void Add(const initializer_list<int> &val)
	{
		v1.insert(v1.end(), val.begin(), val.end());
	}
	void print()
	{
		cout << "vector contents " << endl;
		for (auto &x : v1)
		{
			cout << x << ",";
		}
		cout << endl;
	}
};
//**************************
class CB
{
private:
	list<int> ls1;
public:
	CB(const initializer_list<int> &v) :ls1(v) { }
	void Add(const initializer_list<int> &val)
	{
		ls1.insert(ls1.end(), val.begin(), val.end());
	}
	void print()
	{
		cout << "list contents " << endl;
		for (auto &x : ls1)
		{
			cout << x << ",";
		}
		cout << endl;
	}
};
//************* consumer code ****************
int main()
{
	CA obj1{ 10,20,30,40,50,60 };
	CB obj2{ 59,60,70,50,32,34 };
	obj1.print();
	obj2.print();
	cout << "contents after insertion..." << endl;
	obj1.Add({ 100,200 });
	obj2.Add({ 500,600 });
	obj1.print();
	obj2.print();

	return 0;
}