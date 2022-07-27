#include<iostream>
#include<vector>
using namespace std;

class Data
{
private:
    vector<int> v1;
    vector<float> v2;
    vector<double> v3;
    vector<char> v4;

    //-----------------
    template<typename T> void Add(T x)
    {
        cout <<"Cannot process:" << x << endl;
    }
    void Add(int x)
    {
        v1.push_back(x);
    }

    void Add(float x)
    {
        v2.push_back(x);
    }
    void Add(double x)
    {
        v3.push_back(x);
    }
    void Add(char x)
    {
        v4.push_back(x);
    }

    //----------------
public:
    
    //******Variadic function templates as members of a NON-GENERIC class *****
    template<typename T> void fun(T value)
    {
        this->Add(value);
    }
    
    template <typename T1, typename... T2> void fun(T1 value, T2... args)
    {
        this->Add(value);
        this->fun(args...);
    }

    void print()
    {
        cout <<"values populated onto the vector..." << endl;
        for(auto x:v1){cout << x <<",";}
        cout << endl;
        for(auto x:v2){cout << x <<",";}
        cout << endl;
        for(auto x:v3){cout << x <<",";}
        cout << endl;
        for(auto x:v4){cout << x <<",";}
        cout << endl;
    }
};

//***consumer code**************
int main()
{
    Data obj1;
    obj1.fun(10, 23, 45.12f, 56.78, 200, 'a',"hello");
    obj1.print();
    return 0;
}