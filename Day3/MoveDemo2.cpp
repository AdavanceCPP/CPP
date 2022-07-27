#include<iostream>
using namespace std;

class CA
{
private:
    int a,b;
public:
    CA(int x=0, int y=0):a(x),b(y){cout <<"CA constructor..." << endl;}

    //*****************LVALUE PAIR
    CA(const CA& x):a(x.a),b(x.b)
    {cout <<"CA LVALUE-copy constructor..." << endl;}

    CA& operator =(const CA& x)
    {
        cout <<"CA LVALUE-assignment called..." << endl;
        this->a = x.a;
        this->b = x.b;
        return *this;
    }

    //*********************RVALUE PAIR
    CA(CA&& x):a(x.a),b(x.b)
    {
        cout <<"CA RVALUE-copy constructor..." << endl;
        x.a=0;
        x.b=0;
    }
    CA& operator =(CA&& x)
    {
        cout <<"CA RVALUE-assignment called..." << endl;
        this->a = x.a;
        this->b = x.b;
        x.a=0;
        x.b=0;
        return *this;
    }

    void print() const{cout <<"a = " << a <<",b=" << b << endl;}
};

//***consumer code ************
int main()
{
    //LVALUE IMPLEMENTATIONS...
    CA obj1(10,20), obj2;
    CA obj3(obj1);   //LVALUE COPY
    obj2 = obj3;     //LVALUE ASSIGNMENT
    obj1.print();
    obj2.print();
    obj3.print();
    cout <<"-------------------" << endl;

    CA obj4(50,60), obj5(100,200);
    cout <<"contents of obj4  & obj5 before move copy/assignment.." << endl;
    obj4.print();
    obj5.print();
    cout <<"---------------" << endl;
    CA obj6(std::move(obj4));  // std::move will convert an LVALUE to an RVALUE
    CA obj7;
    obj7 = std::move(obj5);
    cout <<"contents of obj4  & obj5 after move copy/assignment.." << endl;
    obj4.print();
    obj5.print();

    cout <<"contents of obj6  & obj7 after move copy/assignment.." << endl;
    obj6.print();
    obj7.print();
    return 0;
}