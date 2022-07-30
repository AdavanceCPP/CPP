#include<iostream>
#include<optional>
using namespace std;

class CA
{
private:
    int a,b;
public:
    explicit CA(int x=0,int y=0):a(x),b(y){cout <<"CA constructor..." << endl;}
    CA(const CA& x):a(x.a),b(x.b){cout <<"CA LVALUE copy constructor..." << endl;}
    CA(const CA&& x):a(x.a),b(x.b){cout <<"CA RVALUE (MOVE) copy constructor" << endl;}
    ~CA() {cout <<"CA destructor" << endl;}
};

int main()
{
    //optional<CA> op1(CA(10,20));
    optional<CA> op1{std::in_place, 10,20};
 
    optional<CA> op2 = make_optional<CA>(10,20);
    return 0;
}