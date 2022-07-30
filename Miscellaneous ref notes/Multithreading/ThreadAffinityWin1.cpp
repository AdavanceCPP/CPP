#include<iostream>
#include<windows.h>
#include<thread>
using namespace std;

int main()
{
    HANDLE process = GetCurrentProcess();
    DWORD_PTR ProcessAffinityMask = 02;
    BOOL success = SetProcessAffinityMask(process, ProcessAffinityMask);
    SetPriorityClass(process,THREAD_PRIORITY_TIME_CRITICAL);
    cout << boolalpha << success <<  endl;

    system("pause");
    return 0;
}