#include<iostream>
#include<thread>
using namespace std;

bool spawned = false;

class Thread
{
private:
    thread* hThread =nullptr;
    template <typename T, typename... PACK> void run(T x, PACK... Args);
    //bool spawned=false;
public:
    Thread() = default;
    ~Thread();
    
    template <typename T, typename... PACK> auto create(T x, PACK... Args);
    void start();
    void join();
    void detach();
    void stop();
};

Thread::~Thread()
{
    cout <<"destroying thread :" << this_thread::get_id() << endl;
    delete hThread;
    hThread = nullptr;
    //spawned = false;
}

template <typename T, typename... PACK> void Thread::run(T x, PACK... Args)
{
    while(!spawned)
    {
        cout <<"Thread with id:" << this_thread::get_id() <<" started as requested" << endl;
        (*x)(Args...);
    }
    
    cout <<"Thread with id:" << this_thread::get_id() <<" task completed..." << endl;
}

template <typename T, typename... PACK>
    auto Thread::create(T x, PACK... Args)
    {
        
        //hThread = new(nothrow) thread(x, Args...);
        auto lm =[&]()
        {
            this->run(x,Args...);
        };
        cout << "Thread instance is getting launched..." << endl;
        if(!spawned)
        {
            hThread = new(nothrow) thread(lm);
            this_thread::sleep_for(3s);
        }
    }
void Thread::start()
{
    spawned = true;
}
void Thread::stop()
{
    cout <<"STOPPED"<<endl;
    spawned = false;
}

void Thread::join()
{
    hThread->join();
}

void Thread::detach()
{
    hThread->detach();
}
void fun1(int x, int y){cout <<"fun1 called x= " << x <<",y=" << y << endl;}

//**consumer code****
int main()
{
    Thread th1;
    th1.create(&fun1,10,20);

    th1.start();
    th1.detach();
   
   
    //Let's pretend the parent thread is busy doing some work
    this_thread::sleep_for(1s);

    th1.stop();
   
    cout <<"Parent thread completes its task" << endl;
    return 0;
}