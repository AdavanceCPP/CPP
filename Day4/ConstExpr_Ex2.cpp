#include<iostream>
//#include <bits/stdc++.h> 
using namespace std; 
  
// A class with constexpr constructor and function 
class Rectangle 
{ 
    int _h, _w; 
public: 
    // A constexpr constructor 
    constexpr Rectangle (int h, int w) : _h(h), _w(w) {} 
      
    constexpr int getArea () const { return _h * _w; } 
}; 
  

int main() 
{ 
    // Below object is initialized at compile time 
    constexpr Rectangle obj(10, 20); 
    cout << obj.getArea(); 
    //constexpr auto area = obj.getArea();
    //cout << area << endl;
    return 0; 
} 