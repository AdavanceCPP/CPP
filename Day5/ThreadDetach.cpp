#include<iostream>
#include<thread>
using namespace std;

void fun()
{
    cout << "fun called:, its id=" << this_thread::get_id() << endl;
}

int main()
{
    cout << "main thread execution started..., id=" << this_thread::get_id() << endl;
    cout << "spawning a child thread..." << endl;
    thread th1(fun);
    cout << "main thread.. processing statements after spawning child thread..." << endl;

    th1.detach();
    if (th1.joinable())
        th1.join();
    cout << "parent thread main completes.." << endl;
    //system("pause");
    return 0;
}