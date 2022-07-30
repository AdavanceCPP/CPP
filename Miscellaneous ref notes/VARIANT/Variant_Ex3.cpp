#include<iostream>
#include<variant>

using namespace std;
int main()
{
    variant<int,float,double> v1{56.12f};
    auto lm[](auto& x) { cout << x << endl;};

    visit(lm, v1);
    return 0;
}