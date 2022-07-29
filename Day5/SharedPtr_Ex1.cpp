#include<iostream>
#include<memory>
using namespace std;

class CA
{
public:
    CA(){cout <<"CA constructor..." << endl;}
    ~CA(){cout <<"CA destructor..." << endl;}
};

//***consumer code****
void fun4(shared_ptr<CA> p4)
{
    cout <<"fun4, called = use_count:" << p4.use_count() <<endl;
    cout <<"is p4 shared_ptr unique ?" << boolalpha << p4.unique() <<endl;
}

void fun3(shared_ptr<CA> p3)
{
    cout <<"fun3, called = use_count:" << p3.use_count() <<endl;
    cout <<"is p3 shared_ptr unique ?" << boolalpha << p3.unique() <<endl;
    fun4(p3);
}

void fun2(shared_ptr<CA> p2)
{
    cout <<"fun2, called = use_count:" << p2.use_count() <<endl;
    cout <<"is p2 shared_ptr unique ?" << boolalpha << p2.unique() <<endl;
    fun3(p2);
}

void fun1(shared_ptr<CA> p1)
{
    cout <<"fun1, called = use_count:" << p1.use_count() <<endl;
    cout <<"is p1 shared_ptr unique ?" << boolalpha << p1.unique() <<endl;
    fun2(p1);
}

int main()
{
    shared_ptr<CA> p = make_shared<CA>();
    cout <<"main, use_count:" << p.use_count() <<endl;
    cout <<"is p shared_ptr unique ?" << boolalpha << p.unique() <<endl;
    fun1(p);
    return 0;
}