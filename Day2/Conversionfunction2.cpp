#include<iostream>
using namespace std;

class Pointee
{
private:
    int* p;
public:
    Pointee():p(NULL){ }
    Pointee(int* q):p(q){ }
    void print()
    {
        cout <<"Value pointed to by p=" << *p << endl;
    }    
    operator bool()
    {
        if(p != NULL)
            return true;
        else
            return false;
    }
};

//***consumer code***
int main()
{
    Pointee p1;
    Pointee p2(new int(200));
    if(p1)   // if(p1.operator bool())
        p1.print();
    else
        cout <<"p1 handle is invalid" << endl;

    if(p2)        
        p2.print();
    else
        cout <<"p2 handle is invalid" << endl;        
    return 0;
}