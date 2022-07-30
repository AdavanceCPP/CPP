#include<iostream> 
#include<iostream
#include<tuple> // for tuple 
using namespace std; 

//tuple is a fixed-size collection of heterogeneous values

int main() 
{ 
    // Declaring tuple 
    tuple <char, int, float> tp1; 
  
    // Assigning values to tuple using make_tuple() 
    tp1 = make_tuple('a', 10, 15.5); 
  
    // Printing initial tuple values using get() 
    cout << "The initial values of tuple are : "; 
    cout << get<0>(tp1) << " " << get<1>(tp1); 
    cout << " " << get<2>(tp1) << endl; 
  
    // Use of get() to change values of tuple 
    get<0>(tp1) = 'b'; 
    get<2>(tp1) =  20.5; 
  
     // Printing modified tuple values 
    cout << "The modified values of tuple are : "; 
    cout << get<0>(tp1) << " " << get<1>(tp1); 
    cout << " " << get<2>(tp1) << endl; 
  
    return 0; 
} 