#include<iostream>
#include<algorithm>
#include<list>
using namespace std;

class CA
{
private:
    int a,b;
public:
    CA(int x=0,int y=0):a(x),b(y){ }   
    void print() const {cout <<"CA-print, a=" << this->a <<",b=" << this->b << endl;} 
    int GetA(){return a;}
    int GetB(){return b;}
};

//****consumer code********************


int main()
{
    list<CA> ls1;
    for(int i=1;i<=5;i++)
    {
        ls1.push_back(CA(i,i+10));
    }
    
    int Total{};
    int TotalA{},TotalB{};

    auto sumA=[&TotalA](CA& ob) ->void
    {
        TotalA = TotalA + ob.GetA();
    };  

    auto sumB=[&TotalB](CA& ob) ->void
    {
        TotalB = TotalB + ob.GetB();
    };  

    for_each(ls1.begin(),ls1.end(),sumA);
    for_each(ls1.begin(),ls1.end(),sumB);


    Total = TotalA + TotalB;
    cout <<"TotalA = " << TotalA << endl;   
    cout <<"TotalB = " << TotalB << endl;  
    cout <<"Sum total of A and B = " << Total << endl;        
    return 0;
}