#include<iostream>
#include<mutex>
#include<thread>
using namespace std;

 //once_flag flg;
class CA
{
private:
  //..
  once_flag flg;
public:
    CA()=default;
    void print()
    {
        cout <<"CA print called, thread_id:" << this_thread::get_id() << endl;
    }

    void fun1()
    {
        cout <<"fun1 called, thread_id:" << this_thread::get_id() << endl;
        std::call_once(flg,&CA::print,this);
    }

    void fun2()
    {
        cout <<"fun2 called, thread_id:" << this_thread::get_id() << endl;
        std::call_once(flg,&CA::print,this);
    }
};

//*****
int main()
{
    CA obj1;

    /*
        As 'once_flag' instance is a data member, The 'fun1' member function of class 'CA' cannot
        be directly passed as a parameter along with its related CA object to the thread instance.

        An object of a class holding 'once_flag' as its data-member cannot be copy constructed
        onto a thread instance.

        Solution: Rather wrap the member function call and it's related object onto a lambda function.
    */

    // thread th1(&CA::fun1, obj1);
    // thread th2(&CA::fun2, obj1);

    // function<void(void)> lm = ...;
    auto lm1 =[&]()                
    {
        obj1.fun1();
    };

    auto lm2 =[&]()
    {
        obj1.fun2();
    };

    thread th1(lm1);    // thread th1(&function::operator()(), lm);   ==> thread th1(lm.operator()());
    thread th2(lm1);

    th2.join();
    th1.join();
    
    return 0;

    
}