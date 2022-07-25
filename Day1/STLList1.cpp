#include<iostream>
#include<list>
using namespace std;

int main()
{
    list<int> ls1;
    cout <<"initial size of the list:" << ls1.size() << endl;
    //populate the list
    for(int i=1;i<=10;i++)
    {
        ls1.push_front(i);
    }

    cout << endl << "size of the stack after pushing..." << ls1.size() << endl;
    //create an iterator that points to the first node of the list ls1.
    list<int>::iterator itr = ls1.begin();
    cout <<"initial contents of the list:" << endl;
    while(itr != ls1.end())
    {
        cout << *itr <<",";
        itr ++;
    }

    //sort the contents of the list
    ls1.sort();

    itr = ls1.begin();
    cout <<"contents of the list after sorting..." << endl;
    while(itr != ls1.end())
    {
        cout << *itr <<",";
        itr ++;
    }
    
return 0;
}