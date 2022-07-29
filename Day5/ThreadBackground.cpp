#include<iostream>
#include<thread>
using namespace std;

//instead of detaching a thread, provide a global scope, so that this thread
//can keep running till the process runs max.

std::thread th_bgr;

void Backgroundtask()
{
    cout <<"Background task - id:" << this_thread::get_id() << endl;
    cout <<"Task running in the background..." << endl;
    this_thread::sleep_for(2s);
    //..
    cout <<"Task running in the background completes..." << endl;
}

void Sometask()
{
    cout <<"Sometask - id:" << this_thread::get_id() << endl;
    cout <<"Sometask running is running in foreground..." << endl;
    this_thread::sleep_for(2s);
    //..
    cout <<"Sometask task in foreground completes..." << endl;
    //Let the thread for 'Backgroundtask' be spawned just about when 'Sometask'
    //about to complete..
    th_bgr = std::move(thread{Backgroundtask});
}

int main()
{
    cout <<"Parent thread initiated, task-id:" << this_thread::get_id() << endl;
    //...some busy task
    this_thread::sleep_for(2s);
    thread th1(Sometask);
    //...
    th1.join();
    //..
    cout <<"Parent thread completes its task.." << endl;
    //Just when the process is about to terminate.... wait for the background task
    th_bgr.join();
    return 0;
}