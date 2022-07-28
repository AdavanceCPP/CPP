#include<iostream>
using namespace std;

template<typename... PARAMETER_PACK> class CA
{
public:
    CA(){cout <<"Base class CA" << endl;}
};

template<typename PARAMETER_TYPE, typename ... PARAMETER_PACK> 
           class CA<PARAMETER_TYPE, PARAMETER_PACK...> : private CA<PARAMETER_PACK...>
{
private:
	PARAMETER_TYPE data;
public:

	CA(PARAMETER_TYPE h, PARAMETER_PACK... args) :CA<PARAMETER_PACK... >(args...), data(h)
	{
		cout << "No. of elements left further ..." << sizeof...(args) << endl;
		cout << "data " << data << endl;
	}
};

//***************************
int main()
{
	//CA<int, float, double> obj1(10,12.34f, 56.12);
	CA<int, float, int, char> obj1(10, 12.34f, 56, 'c');

    return 0;
}

