#include<iostream>
#include<optional>

using namespace std;

int main()
{
    optional<int> Five{5};
    optional<int> Ten{10};
    optional<int> Empty{};     //nullopt type
    //comparison operation on these types...
    cout << boolalpha ;
    cout << (Five < Ten) << endl;
    cout <<(Five == Ten) << endl;
    cout << (Ten < Five) << endl;
    cout << (Empty == std::nullopt) << endl;
    cout <<"------------------------" << endl;
    cout << *Five << endl;
    optional<string> opstr{};
    try
    {
        if(Empty == std::nullopt)
        {
            throw bad_optional_access();
        }
        else
            cout <<*Empty;

    }
    catch (const std::bad_optional_access &e)
    {
        std::cout << e.what() << '\n';
    }  
    
    return 0;
}