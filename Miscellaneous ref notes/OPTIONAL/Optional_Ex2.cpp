#include<iostream>
#include<optional>
#include<vector>
using namespace std;

//Demo - Different ways of creating 'optional' type instances....

class CA
{
    private:
    int a,b;
    public:
    explicit CA(int x=0,int y=0):a(x),b(y){cout <<"CA constructor..." << endl;}
    ~CA() {cout <<"CA destructor" << endl;}
};


int main()
{
    std::optional<int> op1;   //empty
    std::optional<int> op2=std::nullopt;  //empty
    //-------------------------------
    std::optional<int> op3{10};   //Direct
    std::optional op4{20};        //Direct - Template Deduction Guide
    //--------------------------------
    //helper function 'make_optional'
    auto op5 = make_optional<int>(10);
    auto op6 = make_optional<CA>(10,20);
    //---------------------------
    // with 'in_place' wrapper tag
    std::optional<CA> op7{std::in_place,30,40};
    std::optional<vector<int>> op8{std::in_place,{10,20,30,40}};
    //--------------------
    //by copying
    auto op9 = op1;
    return 0;
}