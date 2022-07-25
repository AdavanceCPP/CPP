#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

//global function

bool Ascending(int &x, int &y)  
{
	if(x < y)
		return true;
	else
		return false;
}


bool Descending(int &x, int &y)   
{
	if(x > y)
		return true;
	else
		return false;
}

//***consumer code*****
int main()
{
    vector<int> ls1;
    for(int i=1;i<=100;i++)
    {
        ls1.push_back(i);
    }
    cout << endl <<"Original contents of the list:" << endl;
    vector<int>::iterator itr = ls1.begin();
    while(itr != ls1.end())
    {
        cout << *itr <<",";
        itr ++;
    }
    cout << endl <<"contents of the list after sorting in Descending order:" << endl;
    sort(ls1.begin(), ls1.end(), Descending);
    itr = ls1.begin();
    while(itr != ls1.end())
    {
        cout << *itr <<",";
        itr ++;
    }
    cout << endl <<"contents of the list after sorting in Ascending order:" << endl;
    sort(ls1.begin(), ls1.end(), Ascending);
    itr = ls1.begin();
    while(itr != ls1.end())
    {
        cout << *itr <<",";
        itr ++;
    }
    return 0;
}