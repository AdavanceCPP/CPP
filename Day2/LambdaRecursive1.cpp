#include<iostream>
#include<functional>
using namespace std;

//A lambda function upon being a global cannot capture data-segment (global - fib) entity
//Example has capture limitation

/*
function<int(int)> fib = [&fib](int x)  ->int
{
	return x <= 2 ? 1 : fib(x - 1)+ fib(x - 2);
};
*/

//the lambda handle 'fib' which by default has global scope is directly visible inside the
//lambda function, there is no need to capture the same. Even capturing it does not make any
//business sense. As capturing is always in the context of the OUTER-SCOPE elements, that is if
//this lambda function happens to be scoped inside another function and not in the global scope.


// function<int(int)> fib = [](int x)  ->int
// {
// 	return x <= 2 ? 1 : fib(x - 1)+ fib(x - 2);
// };

int main()
{
	/* LOCAL LAMBDA WHOSE SCOPE IS main */
	//define a recursive lambda
	 //auto fib = [&fib](int x) 
	 function<int(int)> fib = [&fib](int x)   
	 {
	 	return x <= 2 ? 1 : fib(x - 1) + fib(x - 2);
	 };
    
	cout << fib(10) << endl;

	return 0;
}