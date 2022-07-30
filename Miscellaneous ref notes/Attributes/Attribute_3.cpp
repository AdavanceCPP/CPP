#include<iostream>
#include<string>
using namespace std;

enum class [[nodiscard]] ErrorCode { OK, FATAL_ERROR, SYSTEM_ERROR, FILE_ERROR };


class FileSystem
{
public:
	//Functions return 'ErrorCode' type must be and compulsorily handled by consumer...
	ErrorCode OpenFile(std::string filename)
	{ /* */ return ErrorCode::FILE_ERROR;
	}

	ErrorCode SendEmail(std::string mail_id, std::string text)
	{ /* */ return ErrorCode::OK;
	}

	ErrorCode SystemCall(std::string syscall)
	{ /* */ return ErrorCode::OK;
	}
};

int main()
{
	FileSystem fs;
	fs.OpenFile(std::string("MyFile"));
	//static_cast<void>(fs.OpenFile(std::string("MyFile")));

	fs.SendEmail(std::string("me@gmail.com"), std::string("Hi"));

	fs.SystemCall(std::string("SysFile"));
	//[[maybe_unused]] auto er = fs.SystemCall(std::string("SysFile"));
	return 0;
}