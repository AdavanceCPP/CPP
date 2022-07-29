#include<iostream>
#include<windows.h>
#include<thread>
using namespace std;

void fun()
{
    cout <<"child thread, fun called" << endl;
    HANDLE process = GetCurrentProcess();
    DWORD_PTR ProcessAffinityMask = 02;
    bool success = SetProcessAffinityMask(process, ProcessAffinityMask);
    SetPriorityClass(process,THREAD_PRIORITY_TIME_CRITICAL);
    cout << boolalpha << "success :" << success <<  endl;
}

int main()
{
    cout <<"parent thread" << endl;
    HANDLE process = GetCurrentProcess();
    DWORD_PTR ProcessAffinityMask = 01;
    bool success = SetProcessAffinityMask(process, ProcessAffinityMask);
    SetPriorityClass(process,THREAD_PRIORITY_TIME_CRITICAL);
    cout << boolalpha << "success :" << success <<  endl;

    thread th1(fun);
    th1.join();
    system("pause");
    return 0;
}