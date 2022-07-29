#include<iostream>
#include<thread>
#include<mutex>
#include<memory>
#include<functional>
using namespace std;
once_flag Flag;

class Singleton
{
private:
	inline static shared_ptr<Singleton> ptr;  //C++17 style, no global definition needed
	Singleton() = default;
	
public:
	static auto GetInstance() ->shared_ptr<Singleton>
	{
		auto Only_One = [&]() ->shared_ptr<Singleton>
		{
			if (auto* p= new(nothrow) Singleton(); p) //C++17 - init if
			{
				shared_ptr<Singleton> pt(p);
				ptr.swap(pt);
			}
			return ptr;
		};

		call_once(Flag, Only_One);
		return ptr;
	}
	~Singleton() { cout << "Singleton destructor..." << endl; }
};

//**************************
void client1()
{
	auto tm = Singleton::GetInstance();
	cout << "Id : " << tm.get() << endl;
}

void client2()
{
	auto tm = Singleton::GetInstance();
	cout << "Id : " << tm.get() << endl;
}

int main()
{
	auto tm = Singleton::GetInstance();
	cout << "Id : " << tm.get() << endl;

	thread th1(client1);
	thread th2(client2);

	th1.join();
	th2.join();
	return 0;
}