#include<iostream>
#include<mutex>
#include<thread>
using namespace std;

once_flag flg;

class CA
{
private:
  //..
 
public:
    CA()=default;
    void print()
    {
        cout <<"print, thread-id:" << this_thread::get_id() << endl;
        cout <<"CA print called" << endl;
    }

    void fun1()
    {
        cout <<"fun1, thread-id:" << this_thread::get_id() << endl;
        cout <<"fun1 called" << endl;
        std::call_once(flg, &CA::print, this);
    }

    void fun2()
    {
        cout <<"fun2, thread-id:" << this_thread::get_id() << endl;
        cout <<"fun2 called" << endl;
        std::call_once(flg, &CA::print, this);
    }
};

//*****
int main()
{
    CA obj1;

    thread th1(&CA::fun1, obj1);
    thread th2(&CA::fun2, obj1);
    
    th2.join();
    th1.join();

    return 0;
}