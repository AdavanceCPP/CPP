#include<iostream>
#include<initializer_list>
using namespace std;
//POLICY DESIGN WITH VARIADIC CLASS TEMPLATE
template<int SIZE> class CommandInfo
{
private:
  char arr[SIZE] ={};
public:
    CommandInfo(){ }
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

    void Set(initializer_list<char> s)
    {
        int i = 0;
		if (s.size() <= SIZE)
		{
			for (auto &val : s)
			{
				arr[i] = val;
				++i;
			}
		}
		else
			cout << "Excess parameters, assignment failed" << endl;
    }
    
    void CommandProcess()
    {
        for(auto x:arr)
        {
            if(x)        //checking for blank space
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
    void Setter(){ cout <<"All values Set..." << endl; }
};

template<typename COMMAND, typename ... COMMANDINFO_TYPES> 
           class Command<COMMAND, COMMANDINFO_TYPES...> : private Command<COMMANDINFO_TYPES...>
{
private:
	COMMAND object;
public:
    Command(){ }
    Command(COMMAND h, COMMANDINFO_TYPES... args) :Command<COMMANDINFO_TYPES... >(args...), object(h)
	{	}

	void Process()
	{
		object.CommandProcess();
		Command<COMMANDINFO_TYPES...>::Process();    
	}

    
    template<typename T> void Setter(T& x)
    {
         object.Set(x);
    }
    template<typename T, typename... PACK> void Setter(T x, PACK... Args)
    {
        object.Set(x);
        Command<COMMANDINFO_TYPES... >::Setter(Args...);
    }

    void Init(initializer_list<initializer_list<char>> collection)
    {
        cout <<"initializer_list<initializer_list<char>>" << endl;
        for(auto x:collection)
        {
            Setter(x);
        }
    }
};

//***consumer code****
int main()
{
    //Populating data either thru constructor call or thru 'Setter' function

    //Approach-1
    Command<CommandInfo<6>> commands1({'a','b','c','d','e','t'});
    commands1.Process();
    cout <<"**********************" << endl;
    Command<CommandInfo<3>, CommandInfo<6>> commands2({'1','2','3'},{'a','b','c','d','e','t'});
    commands2.Process();
    cout <<"**********************" << endl;
    //Approach-2
    initializer_list<char> data1{'1','2','3'};
    initializer_list<char> data2{'a','b','c','d','e','t'};
    initializer_list<char> data3{'#','$','%'};

    Command<CommandInfo<3>, CommandInfo<6>,CommandInfo<4>> commands3;
    
    commands3.Setter(data1,data2,data3);
    commands3.Process();
    
    return 0;
}