#include<iostream>
#include<list>
using namespace std;


class MyList   //A RANGE-FOR CONSTRUCT COMPATIBLE CLASS
{
private:
    list<int> ls1 ={10,20,30,40,50,60,70,80,90,100};
public:
    //...
    auto begin()   // list<int>::iterator begin(){ }
    {
        return ls1.begin();
    }
    auto end()     // list<int>::iterator end(){ }
    {
        return ls1.end();
    }    
};

//***consumer code ************
int main()
{
    MyList obj1;
    for(auto x:obj1)
    {
        cout << x <<",";
    }
    cout << endl;
    
    return 0;
}
