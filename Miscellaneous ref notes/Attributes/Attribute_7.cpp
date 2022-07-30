#include<iostream>
using namespace std;

enum class [[nodiscard]] ErrorCode { OK, FATAL_ERROR, SYSTEM_ERROR, FILE_ERROR };


class [[nodiscard]] FileSystem
{
public:
	
};

[[nodiscard]] int fun(int x) //[[expects:x>0]]
{
	return x + 10;
}

int main()
{
	auto x = FileSystem();   //ok

	FileSystem();  //warning
	fun(0);
	return 0;
}