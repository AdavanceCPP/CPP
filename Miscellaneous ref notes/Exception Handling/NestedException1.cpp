
#include<iostream>
#include<exception>
#include<string>
#include<fstream>

using namespace std;
//Example on nested_exception
void print_exception(const exception &e, int level=0)
{
    cout <<"level :" << level << ", Exception...:" << e.what() << endl;
    try
    {
        rethrow_if_nested(e);
       
    }
    catch(const exception &x)
    {
        print_exception(x,level+1);
    }
   // catch(...){}
}


void open_file(const string &s)
{
    cout <<"open_file..." << endl;
    try
    {
        ifstream file(s);
        file.exceptions(ios_base::failbit);
    }
    catch(...)
    {
        throw_with_nested(runtime_error("Could not open file " + s));
    }
}

void run()
{
    cout <<"run..." << endl;
    try
    {
        open_file("MyDatafile");
    }
    catch(...)
    {
        throw_with_nested(runtime_error("run function failed.."));
    }  
}

int main(int argc, char** argv) 
{
    cout <<"main..." << endl;
    try
    {
        run();
    }
    catch(const exception &x)
    {
        print_exception(x);
    }
    return 0;
}

