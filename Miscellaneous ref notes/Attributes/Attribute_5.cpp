// Type your code here, or load an example.
#include<iostream>
#include<memory>
using namespace std;

//class Ptr
class [[nodiscard]] Ptr
{     /* attribute [[nodiscard]] applies to all mem. functions that return */
public:
    static auto Handle1()
    {
        return unique_ptr<int>();
    }

     static auto Handle2()
    {
        return unique_ptr<int>();
    }
};

int main()
{
    //to Hold the handle provided by a call to 'Handle1()' is a must
    //As such the method does not enforce the same on the consumer...
    //which leads to a serious memory resource leak.

    Ptr::Handle1();   //Will never issue a warning

    Ptr::Handle2();   //Will issue a warning
    return 0;
}