#include<iostream>
#include<initializer_list>
using namespace std;

//Non-type template parameter in a variadic class
template<int... PACK> class CA
{
   initializer_list<int> data = {PACK...}; //using in-class initialization
public:
   void display()
   {
       for(auto &x: data)
       {
           cout <<x<<",";
       }
       cout << endl;
   }
};

int main()
{
    CA<10,20,50,30,100> obj1;
    obj1.display();
    
    return 0;
}