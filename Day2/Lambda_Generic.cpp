#include<iostream>
#include<list>
#include<algorithm>
using namespace std;

//Generic lambda = C++14 feature

int main()
{
    list<int> ls1 ={10,20,30,40,50,60,70};
    list<float> ls2 ={56.12f, 89.32f, 77.91f};

    //in C++11
    auto lm_int =[](int x)
    {
        cout << x <<",";
    };

    auto lm_float =[](float x)
    {
        cout <<x <<",";
    };

    for_each(ls1.begin(), ls1.end(),lm_int);
    cout << endl;
    for_each(ls2.begin(), ls2.end(), lm_float);
    cout << endl <<"***************" << endl;
    //GENERIC LAMBDA, the formal parameter use 'auto' type-inference keyword
    auto lm_generic =[](auto x)
    {
        cout <<x <<",";
    };

    for_each(ls1.begin(), ls1.end(),lm_generic);
    cout << endl;
    for_each(ls2.begin(), ls2.end(), lm_generic);

    return 0;
}