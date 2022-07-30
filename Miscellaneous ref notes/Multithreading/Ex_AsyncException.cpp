#include<iostream>
#include<thread>
#include<future>
using namespace std;

int fun()
{
    cout <<"fun execution started..." << endl;
    //very busy with some work...
    this_thread::sleep_for(2s);
    cout <<"fun continuing execution..." << endl;
    throw std::runtime_error("Exception from fun");
    return 100;
}

int main()
{
    std::future<int> ft = async(launch::async, fun);
    //..
    cout <<"###" << endl;
            try
            { 
            auto x = ft.get();  //blocking call
            cout <<"value fetched:" << x << endl;
            }
            catch(std::exception &e)
            {
                cout <<"Exception from async call:" << e.what() << endl;
            }
    cout <<"***" <<endl;
    return 0;
}