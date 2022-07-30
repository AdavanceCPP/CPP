#include<iostream>
#include<thread>
using namespace std;

int g_data=0;
bool notified=false;
int counter=0;

void Getter()
{
    while(true)
    {
        if(!notified)
        {
            counter ++;
            cout <<"not notified..." << counter << endl;
        }
        else
            break;
    }
    cout <<"global data=" << g_data << endl;
}

void Setter()
{
    cout <<"Setter stared..." << endl;
    g_data= 100;
    notified = true;
    cout <<"Setter completed..." << endl;
}

//***consumer code ****
int main()
{
    thread th1(&Getter);
    thread th2(&Setter);

    th1.join();
    th2.join();
   
    return 0;
}