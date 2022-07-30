#include<iostream>
#include<string>
#include<tuple>
using namespace std;

int main()
{
    auto tup_info = make_tuple(200,56.12f,"tie function");
    int x; float y; string s;
    std::tie(x,y,s) = tup_info;
    //x=x+100;
    //cout <<"x:" << x <<",y:" << y <<",s:" << s << endl;
    
    get<0>(tup_info) =300;

    cout << get<0>(tup_info) << endl;
    cout << get<1>(tup_info) << endl;
    cout << get<2>(tup_info) << endl;
    
    cout <<"x:" << x <<",y:" << y <<",s:" << s << endl;
    return 0;
}