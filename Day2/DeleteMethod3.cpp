#include<iostream>
using namespace std;

//Dis-able certain conversions in a Modern way.

class CA
{
private:
    int a,b;
public:
    CA(int x=0, int y=0):a(x),b(y){}    
    explicit operator int()
    {
        cout <<"operator int called" << endl;
        return a+b;
    }

    operator double() = delete;
    operator char() = delete;
};

//***consumer****
int main()
{
    CA obj1(10,20);
    int x;
    x = (int) obj1;  //ok, Approach-1
    //x = obj1;   //Approach-2, will not work as the conversion is tagged 'explicit'
    cout <<"-----------------" << endl;
    //auto y = (char) obj1;
    //auto z = (double) obj1;
    return 0;
}