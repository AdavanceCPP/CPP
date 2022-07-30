#include<iostream>
using namespace std;

enum class [[nodiscard]]  ErrorCode { OK, FATAL_ERROR, SYSTEM_ERROR, FILE_ERROR };


class [[nodiscard]] FileSystem
{
private:
    enum ErrorCode HANDLE;
public:
	//Functions return 'ErrorCode' type must be and compulsorily handled by consumer...
	FileSystem OpenFile(std::string filename) 
	{ 
        /* */ 
        HANDLE=ErrorCode::FILE_ERROR;
        return *this;
    }

	FileSystem SendEmail(std::string mail_id, std::string text) 
	{ 
        /* */ 
        HANDLE=ErrorCode::FILE_ERROR;
        return *this;
    }

	FileSystem SystemCall(std::string syscall) 
	{ 
        /* */ 
        HANDLE=ErrorCode::FATAL_ERROR;
        return *this;
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