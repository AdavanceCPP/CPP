#include<iostream> 
#include<tuple> // for tuple_size and tuple 
using namespace std; 
int main() 
{ 
  
    // Initializing tuple 
    tuple <char,int,float> tp1(20,'g',17.5); 
  
    // find the size of tuple 
    cout << "The size of tuple is : "; 
    cout << tuple_size<decltype(tp1)>::value << endl; 
  
    return 0; 
  
} 