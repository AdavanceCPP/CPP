#include<iostream>
#include<string>
using namespace std;

void fun(int x) { cout << "int:" << x << endl; };
void fun(float x) { cout << "float:" << x << endl; };
void fun(char x) { cout << "char:" << x << endl; };
void fun(const string &x) { cout << "string:" << x << endl; };

template<typename... Pack> void Process(Pack... Args)
{
    auto generic_lm=[](auto& x)   {    fun(x);      };

    (generic_lm(Args), ...);
}

int main()
{
    Process(string("cpp"),string("fold"),200,45.12f,500);
    return 0;
}