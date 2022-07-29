#include<iostream>
#include<thread>
#include<atomic>
using namespace std;

class Counter
{
private:
	//int a;
	atomic<int> a;
public:
	Counter(int x = 0) :a(x) {}
	void Increment_1() 
	{	
		++a; 	
	}
	void Increment_2()
	{
		++a; ++a;
	}
	void Result()const { cout << "Total:" << a << endl; }
};

//***consumer code*****
int main()
{
	Counter obj;
	auto func1 = [&]() 
					{
						for (int i = 1; i <= 1000000; i++)
						{
							obj.Increment_1();
						}
					};

	auto func2 = [&]()
	{
		for (int i = 1; i <= 1000000; i++)
		{
			obj.Increment_2();
		}
	};

	thread th1(func1);   //1000
	thread th2(func2);   //2000

	thread th3(func1);   //1000
	thread th4(func2);   //2000


	th1.join();
	th2.join();
	th3.join();
	th4.join();
	
	obj.Result();

	return 0;
}