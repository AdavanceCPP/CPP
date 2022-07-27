#include<iostream>
#include<vector>
#include<string>
using namespace std;

void disp_vect(const vector<string> &v)
{
	if (v.size() != 0)
	{
		for (auto &x : v)
		{
			cout << x << " ";
		}
		cout << endl;
	}
	else
	{
		cout << "vector is empty" << endl;
	}
}

template<typename T> void MySwap(T &a, T &b)
{
	T temp(move(a));
	a = move(b);
	b = move(temp);
}

int main()
{
	vector<string> v1 = { "one", "two","three", "four", "five" };
	vector<string> v2 = { "six", "seven", "eight", "nine","ten" };

	disp_vect(v1);
	disp_vect(v2);
	
	//cout << "after move" << endl;
	//v2 = move(v1);

	cout << "after swap" << endl;
	MySwap(v1, v2);
	disp_vect(v1);
	disp_vect(v2);
}

