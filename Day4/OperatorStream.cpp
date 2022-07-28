#include<iostream>
using namespace std;

class CA
{
private:
    int a,b;
};

//global operator functions
void operator >>(istream& input, CA& ob)
{
    cout <<"operator >> called" << endl;
}

void operator <<(ostream& print, CA& ob)
{
    cout <<"operator << called" << endl;
}

//***consumer code***********
int main()
{
    CA obj1;
    cin >> obj1;    // operator >>(cin, obj1);
    cout << obj1;   // operator <<(cout, obj1);
    return 0;
}