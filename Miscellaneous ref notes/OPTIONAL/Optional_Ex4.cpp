#include<iostream>
#include<optional>
#include<string>
using namespace std;

class CA
{
private:
    //...
public:
    explicit CA(int x=0,int y=0){cout <<"CA constructor..." << endl;}
    CA(const CA& x) {cout <<"CA copy constructor..." << endl;}
    CA(CA&& x) {cout <<"CA MOVE copy constructor..." << endl;}
    //CA(const CA& x)=delete;  //No COPY support
    //CA(string&& x)=delete;   //No MOVE support
    ~CA() {cout <<"CA destructor" << endl;}
};

int main()
{
    std::optional<CA> op1{};                 // --> std::optional<CA> op1{std::nullopt};
    //std::optional<CA> op2{std::in_place};
    //std::optional<CA> op3{CA(10,20)};   
    //std::optional<CA> op4(in_place,10,20);   
        
    //std::optional<CA> op5 =make_optional<CA>(10,20);
   
    return 0;
}