#include<iostream>
#include<string>
using namespace std;

template<typename T> class Library
{
    friend T;
private:
    string book_title;
    string publisher;
    int book_code;
    //...
};

class Student
{
private:
    Library<Student> data;    //Student is now a friend to Library
public:
    void SetDetails()
    {
        cout << "Student..." << endl;
        data.book_title ="C++ programming";
        data.publisher ="Wiley";
        data.book_code = 1234;
    }
    void GetDetails()
    {
        cout << data.book_title << endl;
        cout << data.publisher << endl;
        cout << data.book_code << endl;
    }
};

class Teacher
{
private:    
    Library<Teacher> data;   //Teacher is now a friend to Library
public:
    void SetDetails()
    {
        cout << "Teacher..." << endl;
        data.book_title ="Modern C++ programming";
        data.publisher ="Prentice Hall";
        data.book_code = 567;
    }
    void GetDetails()
    {
        cout << data.book_title << endl;
        cout << data.publisher << endl;
        cout << data.book_code << endl;
    }
};

//***consumer code ****
int main()
{
    Student s1;
    s1.SetDetails();
    s1.GetDetails();
    cout <<"----------------" << endl;
    Teacher t1;
    t1.SetDetails();
    t1.GetDetails();
    return 0;
}