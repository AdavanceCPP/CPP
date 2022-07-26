#include<iostream>
using namespace std;
/*
    Conversion function:
        - Overloading data-types (standard/user-defined type) as function
          name is called conversion function.
        - These functions must and should return a value whose type must
          be 'function-name'. As such we are not supposed to state the
          return-type of the function explicitly.
        - Conversion functions do not take any known formal parameters.
*/
class CA
{
private:
    int a,b;
public:
    CA():a(0),b(0){ cout <<"CA default constructor" << endl; }
    explicit CA(int x):a(x),b(x){cout <<"CA one arg.constructor" << endl;}
    CA(int x, int y):a(x),b(y){ cout <<"two arg. constructor.." << endl; } 
    ~CA(){cout <<"CA destructor" << endl;}
    void operator =(int z)
    {
        a = z;
        b = z;
    }
    operator int()
    {
        cout <<"operator int called" << endl;
        return a+b;
    }
};

//***consumer code***
int main()
{
    CA obj1(10,20);
    int x;
    //assignment
    obj1 = x;   // obj1 = CA(x);

    //Approach-1
    x = obj1;  // x = (int) obj1;   // obj1.operator int();
    //Approach-2
    cout << (int) obj1 << endl;  // cout << obj1.operator int() << endl;
    return 0;
}