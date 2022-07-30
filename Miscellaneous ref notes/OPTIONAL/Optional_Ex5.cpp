#include<iostream>
#include<optional>
#include<string>
using namespace std;

class MyString
{
private:
    std::string name;
public:
    MyString()=default;
    MyString(std::string n):name(n){cout <<"MyString constructor, name:"<< name << endl;}
    ~MyString(){cout <<"MyString destructor name:" << name << endl;}
    std::string Info() { return this->name;}
};

int main()
{
    auto op1 = make_optional<MyString>();
    //auto op1 = make_optional<MyString>("hello");

    //auto s = op1->Info();
    //if (!s.empty())
    if(auto s = op1->Info(); !s.empty())
    {
        cout << op1->Info() << endl;
        cout << (op1.value()).Info() << endl;
        cout << (*op1).Info() << endl;
    }
    else
    {
        cout << "Info... nullopt" << endl;
    }
    return 0;
}