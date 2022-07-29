#include<iostream>
#include<thread>
using namespace std;

class CA
{
private:
	int a, b;
public:
	CA(int x = 0, int y = 0) :a(x), b(y) { cout << "CA constructor" << endl; }
	~CA() { cout << "CA destructor" <<  endl; }
	CA(const CA &x) :a(x.a), b(x.b) { cout << "CA copy constr. called" << endl; }
	CA(CA &&x) :a(x.a), b(x.b) { x.a=0; x.b=0; cout << "CA move copy constr." << endl; }
	CA& operator =(CA &&x)
	{
		cout << "move assignment" << endl;
		a = move(x.a);
		b = move(x.b);
		return *this;
	}
	void print()const { cout << "CA-print, a=" << a<<",b=" << b << endl; }
	void Set(int x, int y)
	{
		a = x; b = y;
		cout <<"CA-Set(int x, int y) called, a=" << a<< ",b=" << b << endl;
	}
};

int main()
{
	cout << "main thread execution started..." << endl;
	CA obj1(10, 20);

	//spawning a class member function as a thread
	thread th1(&CA::print, obj1);   //LValue copy constructed.
	th1.join();

	cout << "---------------" << endl;
	thread th2(&CA::print, CA(30, 40));   //RValue copy constructed.
	th2.join();
	cout << "---------------" << endl;

	CA obj2;
	thread th3(&CA::Set, obj2, 50, 60);
	th3.join();
	cout << "---------------" << endl;

	return 0;
}