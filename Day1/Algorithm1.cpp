#include<iostream>
#include<list>
#include<algorithm>
using namespace std;

void Even(int x)
{
    if((x%2)==0)
        cout << x <<",";
}

int main()
{
    list<int> ls1;
    for(int i=1;i<=100;i++)
    {
        ls1.push_back(i);
    }

    for_each(ls1.begin(), ls1.end(),Even);
    return 0;
}