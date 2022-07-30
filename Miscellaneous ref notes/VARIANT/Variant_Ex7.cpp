#include<iostream>
#include<variant>
#include<vector>
using namespace std;

//Un-Related classes, with different behaviours in their classes

class c_One
{
public:
    c_One(){cout <<"c_One constructor called" << endl;}
    void fun1() const {cout <<"c_One fun1() called" << endl;}
    ~c_One(){cout <<"c_One destructor called" << endl;}
    
};
class c_Two
{
public:
    c_Two(){cout <<"c_Two constructor called" << endl;}
    void fun2() const {cout <<"c_Two fun2() called" << endl;}
    ~c_Two(){cout <<"c_Two destructor called" << endl;}
};
//....

//A callable entity
class Callable
{
public:
    void operator()(const c_One& x)
    {
        x.fun1();
    }
    void operator()(const c_Two& x)
    {
        x.fun2();
    }
};

int main()
{
    vector<variant<c_One, c_Two>> vect ={move(c_One()), move(c_Two())};
    for(auto &x: vect)
    {
        visit(Callable(), x);
    }
    
    return 0;
}
