#include<iostream>
#include<vector>
using namespace std;

int main()
{
	vector<int> v1;
	//populate the vector
	for (int i = 1; i <= 10; i++)
	{
		v1.push_back(i);
	}
	//traverse the vector
	cout << "initial contents of the vector.." << endl;
	vector<int>::iterator itr = v1.begin();
	while (itr != v1.end())
	{
		cout << *itr << ",";
		itr++;
	}
	
	//Insert additional values at the 3rd offset from beginning
	itr = v1.begin();
	itr += 2;                    // itr.operator +=(2);
	v1.insert(itr, 100);
	itr = v1.begin();
	itr+=3;
	v1.insert(itr, 200);
	cout << endl << "contents of the vector after insertion..." << endl;

	//---re-position the iterator to the beginning
	itr = v1.begin();
	while (itr != v1.end())
	{
		cout << *itr << ",";
		itr++;
	}
	return 0;
}