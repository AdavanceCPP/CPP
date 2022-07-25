#include<iostream>
#include<stack>
using namespace std;

int main()
{
    stack<int> s1;
    cout <<"initial size of the stack:" << s1.size() << endl;
    //populate the stack
    cout <<"pushing...." ;
    for(int i=1;i<=10;i++)
    {
        s1.push(i);
        cout << s1.top() <<",";
    }
    cout <<endl <<"size of the stack after pushing..." << s1.size() << endl;
    cout <<"popping...";
    while(!s1.empty())
    {
        cout << s1.top() <<",";
        s1.pop();
    }
    cout << endl << "size of the stack after popping..." << s1.size() << endl;
    return 0;
}