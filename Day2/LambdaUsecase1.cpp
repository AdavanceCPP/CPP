#include<iostream>
#include<list>
#include<algorithm>
using namespace std;

class CA
{
private:
    int a,b;
public:
    CA(int x=0, int y=0):a(x),b(y){ }    
    void print() const {cout <<"CA-print, a=" << a <<",b=" << b << endl;}
    void operator()(CA& ob)
    {
        cout <<"functor call, a=" << ob.a <<",b=" << ob.b << endl;
    }
};

void Print(CA& ob)
{
    ob.print();
}

int main()
{
    list<CA> ls1;
    for(int i=1;i<=10;i++)
    {
        ls1.push_back(CA(i,i+10));
    }

    //Approach-1
    list<CA>::iterator itr = ls1.begin();
    while(itr != ls1.end())
    {
        itr->print();
        itr ++;
    }
    cout <<"-----------------------" << endl;
    //Approach-2
    for_each(ls1.begin(), ls1.end(), Print);
    cout <<"------------------" << endl;
    //approach-3
    CA obj1;
    for_each(ls1.begin(), ls1.end(), obj1);
                           //, obj1.operator()(object_from_ls1);
    return 0;
}