#include<iostream>
#include<thread>
#include<memory>
#include<windows.h>
using namespace std;
/*
    - An conceptual approach in trying to bridge or overcome C++11 thread library
      deficieny by mapping to windows native API's to force a thread onto a
      specific core.
*/
class WinThreadInterface
{
private:
  HANDLE process = GetCurrentProcess();
  DWORD_PTR Core_Affinity;
  DWORD ThreadPriority;
  bool success = SetProcessAffinityMask(process,Core_Affinity);
public:
    WinThreadInterface(DWORD_PTR Affinity, DWORD Priority):Core_Affinity(Affinity), ThreadPriority(Priority)
    {
       SetPriorityClass(process,ThreadPriority);
    }
    virtual void ThreadFunc()=0;
};

void fun1()
{
    DWORD64 dwProcessAffinity, dwSystemAffinity;
    GetProcessAffinityMask(GetCurrentProcess(), &dwProcessAffinity, &dwSystemAffinity);
    cout <<"child thread...fun1 called, Process on CORE->" << dwProcessAffinity  << endl;
}
void fun2()
{
    DWORD64 dwProcessAffinity, dwSystemAffinity;
    GetProcessAffinityMask(GetCurrentProcess(), &dwProcessAffinity, &dwSystemAffinity);
    cout <<"child thread...fun2 called, Process on CORE->" << dwProcessAffinity  << endl;
}

class CoreOne final :public WinThreadInterface
{
public:
    CoreOne(DWORD_PTR Affinity, DWORD Priority):WinThreadInterface(Affinity,Priority)
    {    }

    void ThreadFunc() override
    {
        thread th1(&fun1);
        th1.join();
        //To check for affinity in TaskManager on windows O/S if you wish, else comment it
        system("pause");  
    }
};

class CoreTwo final:public WinThreadInterface
{
public:
    CoreTwo(DWORD_PTR Affinity, DWORD Priority):WinThreadInterface(Affinity,Priority)
    {    }

    void ThreadFunc() override
    {
        thread th1(&fun2);
        th1.join();
        //To check for affinity in TaskManager on windows O/S if you wish, else comment it
        system("pause");
    }
};

int main()
{
                                                               //[CORE, THREAD-PRIORITY]
    unique_ptr<WinThreadInterface> ptr1 = make_unique<CoreOne>(1,THREAD_PRIORITY_TIME_CRITICAL);
    ptr1->ThreadFunc();
    unique_ptr<WinThreadInterface> ptr2 = make_unique<CoreTwo>(2,THREAD_PRIORITY_TIME_CRITICAL);
    ptr2->ThreadFunc();
    return 0;
}

