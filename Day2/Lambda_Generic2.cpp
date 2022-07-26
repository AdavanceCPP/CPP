#include<iostream>
using namespace std;

namespace One
{
    namespace Two
    {
        namespace Three
        {
            class CA
            {
                public:
                  void print()
                  {
                    cout <<"One::Two::Three CA::print called" << endl;
                  }
            };
        }
    }
}

//***consumer code ****
int main()
{
    //C++11 approach
    auto non_generic_lambda = [](One::Two::Three::CA& ob)
    {
        ob.print();
    };

    One::Two::Three::CA obj1;

    non_generic_lambda(obj1);
    cout <<"---------------------" << endl;
    //C++14 approach
    auto generic_lambda =[](auto& ob)
    {
        ob.print();
    };
    //in the above lambda declaration 'auto' alone implies 'One::Two::Three::CA'
    generic_lambda(obj1);
    
    return 0;
}