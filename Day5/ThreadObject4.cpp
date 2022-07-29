#include<iostream>
#include<thread>
using namespace std;

class CA
{
private:
	int a;
	static int b;
public:
	CA(int x = 0) :a(x) { b = b + 1; }
	~CA() { cout << "CA destructor" << endl; }
	static void count() { cout << "CA-count, total objects " << b << endl; }
	void operator()()  //FUNCTOR
	{
		cout << "CA-Function operator, a=" << a << endl;
	}
};

int CA::b;

int main()
{
	CA obj1;
	//A thread that would spawn a static member function of a class
	thread th1(&CA::count);
	th1.join();
	cout << "---------------" << endl;

	//A thread that would spawn a FUNCTOR member function
	thread th2(obj1);   // thread th2(&CA::operator()(), obj1);
	th2.join();
	cout << "---------------" << endl;

	return 0;
}