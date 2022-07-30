#include<iostream>
#include<thread>
#include<mutex>
#include<condition_variable>

using namespace std;
std::mutex mx;
std::condition_variable cv;

int g_data=0;
bool notified=false;

void Getter()
{
    unique_lock<mutex> lock(mx);
    while(!notified)
    {
        cv.wait(lock);
    }
    cout <<"global data=" << g_data << endl;
}

void Setter()
{
    g_data= 100;
    notified = true;
    cv.notify_all();
}

//***consumer code ****
int main()
{
    thread th1(&Getter);
    thread th2(&Getter);
    thread th4(&Setter);
    thread th3(&Getter);
    

    this_thread::sleep_for(3s);  //parent is busy with its work

    th1.join();
    th2.join();
    th3.join();
    th4.join();
    return 0;
}