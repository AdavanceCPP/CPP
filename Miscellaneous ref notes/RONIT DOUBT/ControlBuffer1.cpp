#include<iostream>
using namespace std;
//POLICY DESIGN WITH VARIADIC CLASS TEMPLATE
template<int SIZE> class CommandInfo
{
private:
  char arr[SIZE] ={};
public:
    CommandInfo(initializer_list<char> data)
    {
        int i = 0;
		if (data.size() <= SIZE)
		{
			for (auto &val : data)
			{
				arr[i] = val;
				++i;
			}
		}
		else
			cout << "Excess parameters, initialization failed" << endl;
    }
    void CommandProcess()
    {
        for(auto x:arr)
        {
            cout << x <<",";
        }
        cout << endl;
    }
};

template<typename... COMMANDINFO_TYPES> class Command
{
public:
    Command(){ }
	void Process() { cout <<"Processed all Command Info data...." << endl;}
};

template<typename COMMAND, typename ... COMMANDINFO_TYPES> 
           class Command<COMMAND, COMMANDINFO_TYPES...> : private Command<COMMANDINFO_TYPES...>
{
private:
	COMMAND object;
public:
    Command(COMMAND h, COMMANDINFO_TYPES... args) :Command<COMMANDINFO_TYPES... >(args...), object(h)
	{	}
	void Process()
	{
		object.CommandProcess();
		Command<COMMANDINFO_TYPES...>::Process();    
	}
};

//***consumer code****
int main()
{
    //Populating data only thru constructor call.
    Command<CommandInfo<6>> commands1({'a','b','c','d','e','t'});
    commands1.Process();
    Command<CommandInfo<3>, CommandInfo<6>> commands2({'1','2','3'},{'a','b','c','d','e','t'});
    commands2.Process();
    return 0;
}