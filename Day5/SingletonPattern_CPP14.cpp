#include<iostream>
#include<thread>
#include<mutex>
#include<memory>
using namespace std;
once_flag Flag;

class Singleton
{
private:
	static shared_ptr<Singleton> ptr;
	Singleton() = default;
public:
	static auto GetInstance() 
	{
		//---lambda definition begins....
		auto Single_Instance = [&]()
		{
			Singleton* p = new(nothrow) Singleton();
			if (p)
			{
				shared_ptr<Singleton> pt(p);
				ptr.swap(pt);
			}
			return ptr;
		};
		//---lambda definition ends...

		call_once(Flag, Single_Instance);  //Invoke the lambda
		return ptr;
	}
	~Singleton() { cout << "Singleton destructor..." << endl; }
};
//define memory for the static data member in the global scope...
shared_ptr<Singleton> Singleton::ptr;  
//******************
void client1()
{
	auto tm = Singleton::GetInstance();
	cout << "Id : " << tm.get() << endl;
	cout <<"Use count =" << tm.use_count() << endl;
}

void client2()
{
	auto tm = Singleton::GetInstance();
	cout << "Id : " << tm.get() << endl;
	cout <<"Use count =" << tm.use_count() << endl;
}

int main()
{
	auto tm = Singleton::GetInstance();
	cout << "Id : " << tm.get() << endl;
	cout <<"Use count =" << tm.use_count() << endl;
	
	thread th1(client1);
	thread th2(client2);
	
	th1.join();
	th2.join();
	return 0;
}