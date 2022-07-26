#include<iostream>
using namespace std;

/*
    - DELEGATING CONSTRUCTOR : A feature by which it is possible to call
      a constructor belonging to the same class in the initialiation list
      of another constructor.
*/

class Error
{
private:
   int code;
   const char* message;
   //...
   Error(int x, const char* msg):code(x),message(msg)
   { 
    cout <<"Error 2 arg constructor called" << endl;
   }
public:
  Error():Error(0,"OK")
  { 
    cout <<"Error default constructor called" << endl;
  }
  
  Error(int x) :Error(x,"NOT OK")
  {
    cout <<"Error 1 arg constructor called" << endl;
  }   
};

//***consumer code ****
int main()
{
    Error obj1;
    
    return 0;
}