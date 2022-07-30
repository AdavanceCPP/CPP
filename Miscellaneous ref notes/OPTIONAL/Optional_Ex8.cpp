#include<iostream>
#include<optional>
#include<string>
using namespace std;

class EmpRecord
{
private:
    string firstname;
    optional<string>lastname;
    optional<int> age;
public:
    EmpRecord(string fname, optional<string> lname, optional<int> x):firstname(move(fname)),
                                                                     lastname(move(lname)),
                                                                     age(move(x))
    { }
    friend ostream& operator <<(ostream& print, const EmpRecord& emp);

};

ostream& operator <<(ostream& print, const EmpRecord& emp)
{
    print <<"first name:" << emp.firstname << endl;
    if(emp.lastname)
    {
        print <<"last name:" << *emp.lastname << endl;
    }
    if(emp.age)
    {
        print <<"age:" << emp.age.value() << endl;
    }
    return print;
}

int main()
{
    EmpRecord Emp1{"vishwa","kumar",25};
    EmpRecord Emp2{"Ramesh",std::nullopt,28};
    EmpRecord Emp3{"Prakash",std::nullopt,std::nullopt};
    cout << Emp1;
    cout <<"******************" << endl;
    cout << Emp2;
    cout <<"******************" << endl;
    cout << Emp3;

    return 0;
}