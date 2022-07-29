#include<iostream>
#include<mutex>
#include<thread>
using namespace std;

once_flag flg;

class CA
{
private:
  //..
  //once_flag flg;
public:
    CA()=default;
    void print()
    {
        cout <<"CA print called" << endl;
    }

    void operator()()
    {
        cout <<"operator()() called" << endl;
        std::call_once(flg,&CA::print,this);
    }

};

//*****
int main()
{
    CA obj1;
    /*
        With functor overloaded the instance is a callable entity, the 'once_flag'
        cannot serve as a data member, it has to be global instance.
    */

    thread th1(obj1);    // thread th1(&CA::operator()(), obj1);
    thread th2(obj1);

    th2.join();
    th1.join();

    return 0;

    
}