#include<iostream>
#include<thread>
using namespace std;

class Thread
{
private:
    thread* hThread;
    bool stopped;
    void run();
public:
    Thread();
    ~Thread();

    void start();
    void stop();
    void join();
    void detach();
};

Thread::Thread()
{
    hThread = nullptr;
    stopped = false;
}

Thread::~Thread()
{
    cout <<" destroying thread:" << (*hThread).get_id() << endl;
    //cout <<"destroying thread :" << this_thread::get_id() << endl;
    delete hThread;
    hThread = nullptr;
}

void Thread::run()
{
    while(!stopped)
    {
        cout <<"Thread id :" << this_thread::get_id() << endl;
        this_thread::sleep_for(3s);
    }
    cout <<"Thread with id:" << this_thread::get_id() <<" stopped as requested" << endl;
}

void Thread::start()
{
    hThread = new(nothrow) thread(&Thread::run, this);
}

void Thread::stop()
{
    stopped = true;
}

void Thread::join()
{
    hThread->join();
}

void Thread::detach()
{
    hThread->detach();
}

//**consumer code****
int main()
{
    Thread th1, th2, th3;
    th1.start();
    th2.start();
    th3.start();

    th1.detach();
    th2.detach();
    th3.detach();
   
    //Let's pretend the parent thread is busy doing some work
    this_thread::sleep_for(3s);

    th1.stop();
    th2.stop();
    th3.stop();

    this_thread::sleep_for(3s);
    cout <<"Parent thread completes its task" << endl;
    return 0;
}