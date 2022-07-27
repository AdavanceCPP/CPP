#include<iostream>
using namespace std;

class CArray
{
private:
    int a[10] = {10,20,30,40,50,60,70,80,90,100};
public:
    void print()
    {
        /*
        for(int i=0;i<10;i++)
        {
            cout << a[i] <<",";
        }
        */
        for(auto x:a)
        {
            cout << x <<",";
        }
        cout << endl;
    }
    /*
      Try and make our 'CArray' type instances are range-for construct
      compatible on the consumer end.
    */
    int* begin()
    {
        return a;
    }

    int* end()
    {
        return &a[10];
    }
};

//***consumer code************
int main()
{
    CArray obj1;
    //obj1.print();


   for(auto x: obj1)
   {
       cout << x <<",";
   }
   
    return 0;
}