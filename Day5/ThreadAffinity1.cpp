#include<iostream>
#include<thread>
#include<mutex>
#include<vector>
#include<processthreadsapi.h>
using namespace std;

int main(int argc, const char** argv) 
{
    constexpr unsigned num_threads = 4;
    // A mutex ensures orderly access to std::cout from multiple threads.
    std::mutex iomutex;
    std::vector<std::thread> threads(num_threads);
    for (unsigned i = 0; i < num_threads; ++i) 
    {
        threads[i] = std::thread([&iomutex, i] 
        {
            while (1) 
            {
                {
                    // Use a lexical scope and lock_guard to safely lock the mutex only
                    // for the duration of std::cout usage.
                    std::lock_guard<std::mutex> iolock(iomutex);
                    //std::cout << "Thread #" << i << ": on CPU " << sched_getcpu() << "\n";
                    std::cout << "Thread #" << i << ": on CPU " << GetCurrentProcessorNumber() << "\n";
                }

            // Simulate important work done by the tread by sleeping for a bit...
            std::this_thread::sleep_for(std::chrono::milliseconds(900));
            }
        });
 }

    for (auto& t : threads) 
    {
     t.join();
    }
    return 0;
}