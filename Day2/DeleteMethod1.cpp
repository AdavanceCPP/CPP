#include<iostream>
using namespace std;

/*
For Eg: in the traditonal C++ world, we as class authors wished, that instances 
of our class should not be allowed for copy construction nor assignment operation, 
then the only way was to define or declare our own methods under the 'private' 
access-specifier of the class.
*/

class CA   //Traditional C++ class
{
private:
   CA(const CA& );
   CA& operator =(const CA& );
public:
    //all other methods will be defined under public
    CA()=default;
};          
        
//A modern approach to address the above stated problem:

class CB
{
public:
    CB()=default;
    CB(const CB& x) = delete;
    CB& operator =(const CB& x) = delete;
};  

//class consumers...
int main()
{
    /*
    CA obj1;
    CA obj2(obj1);
    CA obj;
    obj2 = obj1;
    */
    
    CB obj3;
    CB obj4(obj3);
    CB obj5;
    obj5 = obj3;
    
    return 0;
}