#include<iostream>
#include<thread>
#include<future>
using namespace std;

/*
    C++11 thread class instances which help us spawn a thread, by default are not
    capable of helping us hold return value of a function.

    Solution: 
        - If there is a function returning a value and would like to spawn it as a
          thread, then do not provide this function as direct parameter to a thread
          class instance, rather wrap this function in an object of the type
          'packaged_task'.

        - Then associate this 'packaged_task' object with an object of the type 'future'. 
          Once associated, the packaged_task instance and the future class instance 
          will point to a shared_memory.
        
        - Then pass the packaged_task class instance as a parameter to the thread 
          object and spawn it as a thread.

        - After the thread 'join' we can be sure the function would have yeilded the
          return result. This return result of the function would have got deposited
          onto the shared_memory associated by the future object.

        - We fetch the value from the shared_memory with help of 'get' member function
          call of the 'future' class object.

        - Once the value is read from the shared_memory with 'get' call, this shared_mem
          will get automatically de-allocated and the future object will go into an
          invalid state.
*/

int fun1(int x)
{
    cout <<"fun1 called with input :" << x << endl;
    return x*x;
}

int main()
{
    packaged_task<int(int)> task(fun1);
    future<int> ft = task.get_future();

    thread th1(std::move(task), 10);
    th1.join();
    int result;
    if(ft.valid())
        result = ft.get();
    cout <<"return result, obtained from fun1:" << result << endl;
    if(!ft.valid())
    {
        cout <<"future is invalid state.. "<<endl;
    }
    return 0;
}

