#include<iostream>
#include<thread>
using namespace std;

class CA
{
private:
	int a, b;
public:
	CA(int x = 0, int y = 0) :a(x), b(y) { cout << "CA constructor" << endl; }
	void print()const { cout << "CA-print, a=" << a << ",b=" << b << endl; }
	void set(int x, int y) { cout << "CA-Set, called" << endl; a = x; b = y; }
};

int main()
{
	CA obj(30, 40);
	//Lambda's as thread parameter
	thread th1([&]() {obj.print(); });
	th1.join();
	cout << "----------------" << endl;

	CA obj2;
	int a = 10, b = 20;

	thread th2([&obj2](int x, int y) {obj2.set(x, y); },a,b);

	th2.join();
	obj2.print();
	cout << "----------------" << endl;

	auto lm = [&obj](int x, int y) {obj.set(x, y); };
	
	thread th3(lm, 50, 60);

	th3.join();
	obj.print();

	return 0;
}