#include<iostream>
#include<variant>
#include<vector>
using namespace std;

using var_data = variant<int,float,const char*>;

int main()
{
    vector<var_data> v1 ={10,20,30,45.12f,"hi",200,"cpp",45.21f};

    auto lm =[](auto x){cout << x << ",";};
    

    for(auto &x:v1)
    {
        visit(lm,x);
    }
    return 0;
}