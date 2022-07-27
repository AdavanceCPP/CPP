#include<iostream>
using namespace std;

class CA
{
public:
    CA(){cout <<"CA default constructor..." << endl;}
    //LVALUE PAIR
    CA(const CA& x) {cout <<"CA LVALUE copy constructor called" << endl;}
    CA& operator = (const CA& x) 
    {
        cout <<"CA LVALUE assignment called" << endl;
        return *this;
    }

    //RVALUE PAIR
    CA(CA&& x) {cout <<"CA RVALUE copy constructor called" << endl;}
    CA& operator = (CA&& x) 
    {
        cout <<"CA RVALUE assignment called" << endl;
        return *this;
    }
};

//****consumer code ***********
int main()
{
    CA obj1;
    CA obj2(obj1);
    obj2 = obj1;
    cout <<"-----------------" << endl;
    CA obj3;
    CA obj4(std::move(obj3));  //std::move converts an LVALUE type to an RVALUE type
    obj4 = std::move(obj3);
    return 0;
}