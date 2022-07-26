#include<iostream>
using namespace std;

/*
    - DELEGATING CONSTRUCTOR : A feature by which it is possible to call
      a constructor belonging to the same class in the initialiation list
      of another.
*/

class Error
{
private:
   int code;
   const char* message;
   //Normal function
   void Init(int x, const char* msg)
   { 
    cout <<"Init method called" << endl;
    code = x;
    message = msg;
   }
public:
  Error()
  { 
    cout <<"Error default constructor called" << endl;
    Init(1,"OK");
  }
  
  Error(int x) 
  {
    cout <<"Error 1 arg constructor called" << endl;
    Init(x,"NOT OK");
  }   
};

//***consumer code ****
int main()
{
    Error obj1;
    
    return 0;
}