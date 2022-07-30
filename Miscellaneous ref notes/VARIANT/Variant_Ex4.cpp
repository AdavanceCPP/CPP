#include<iostream>
#include<variant>
#include<vector>
using namespace std;

class MyFunctor
{
public:
    void operator()(int x){cout << x << endl;}
    void operator()(float x){cout << x << endl;}
    void operator()(const char* x){cout << *x << endl;}
};

using var_data = variant<int,float,const char*>;

int main()
{
    vector<var_data> v1 ={10,20,30,45.12f,"hi",200,"cpp",45.21f};

    MyFunctor obj;
   
    for(auto &x:v1)
    {
        visit(obj,x);
    }
    return 0;
}