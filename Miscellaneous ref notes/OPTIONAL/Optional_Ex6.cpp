#include<iostream>
#include<optional>
#include<string>
using namespace std;

class MyString
{
private:
    std::string name;
public:
    MyString(){ cout <<"MyString default constructor..." << this << endl;}
    MyString(std::string n):name(n){cout <<"MyString constructor, name:"<< this <<"->" <<name << endl;}
    ~MyString(){cout <<"MyString destructor :" << this <<"->" <<  name << endl;}
    std::string Info() { return this->name;}
};

int main()
{
    auto op1 = make_optional<MyString>();
    op1.emplace("CPP17");
    op1.emplace("Optional");

    //op1.reset();
    op1 = MyString{"assigning new string"};
    return 0;
}