#include<iostream>
using namespace std;

class CA
{
private:
    int a,b;
public:
    CA(int x=0, int y=0):a(x),b(y){cout <<"CA constructor..." << endl;}
    //LVALUE PAIR
    CA(const CA& x):a(x.a),b(x.b){cout <<"CA LVALUE-copy constructor..." << endl;}
    CA& operator =(const CA& x)
    {
        cout <<"CA LVALUE-assignment called..." << endl;
        this->a = x.a;
        this->b = x.b;
        return *this;
    }

    void print() const{cout <<"a = " << a <<",b=" << b << endl;}
};
//The wrapper class CB is likely to manage the HEAP memory for CA type instances..
//without the consumer of class CB having to use 'new/delete' operator functions.
class CB
{
private:
    CA* p;                  //PIMPL model - Pointer implementation model
public:
    //RAII - Resource acquistion is intialization...
    CB(int x=0, int y=0)
    {
        p = new(nothrow) CA(x,y);
    }  
    ~CB()
    {
        if(p)
        {
            delete p;
        }
    } 

    operator bool()
    {
        if(p != nullptr)
            return true;
        else
            return false;
    } 

    //LVALUE PAIR - DEEP COPY & DEEP ASSIGNMENT
    CB(const CB& x)
    {
        cout <<"CB - Deep copy..." << endl;
        p = new(nothrow) CA(*(x.p));   //Will call CA copy constructor if any
    }

    CB& operator =(const CB& x)
    {
        cout <<"CB = deep assignment..." << endl;
        *(this->p) = *(x.p);  //Will call CA assignment function if any
        return *this;
    }

    //RVALUE PAIR - SHALLOW COPY & SHALLOW ASSIGNMENT
    CB(CB&& x):p(x.p)
    {
       cout <<"CB - shallow copy..." << endl;
       x.p = nullptr;
    }

    CB& operator =(CB&& x)
    {
        cout <<"CB - shallow assignment..." << endl;
        delete this->p;
        this->p = x.p;
        
        x.p = nullptr;
        return (*this);
    }

    void print(){p->print();}
};

//***consumer code***************
int main()
{
    
     CB obj1(10,20);
     obj1.print();
     cout <<"----LVALUE COPY--------" << endl;
     CB obj2(obj1);

     if(obj1)           // if(obj1.operator bool())
         obj1.print();
     else
         cout <<"obj1 handle is not valid" << endl;

     if(obj2)           // if(obj2.operator bool())
         obj2.print();
     else
         cout <<"obj2 handle is not valid" << endl;
     cout <<"----LVALUE ASSIGNMENT--------" << endl;
     CB obj3(40,50),obj4;
     obj4 = obj3;

     if(obj3)           
         obj3.print();
     else
         cout <<"obj3 handle is not valid" << endl;

      if(obj4)          
         obj4.print();
     else
         cout <<"obj4 handle is not valid" << endl;
    cout <<"***********************************" << endl;
    
    
    //RVALUE IMPLEMENTATION
    /*
    CB obj1(10,20);
    obj1.print();
    cout <<"----RVALUE COPY--------" << endl;
    CB obj2(std::move(obj1));

    if(obj1)           // if(obj1.operator bool())
        obj1.print();
    else
        cout <<"obj1 handle is not valid" << endl;

    if(obj2)           // if(obj2.operator bool())
        obj2.print();
    else
        cout <<"obj2 handle is not valid" << endl;
    cout <<"----RVALUE ASSIGNMENT--------" << endl;
    CB obj3(40,50),obj4;
    obj4 = std::move(obj3);

    if(obj3)           
        obj3.print();
    else
        cout <<"obj3 handle is not valid" << endl;

     if(obj4)          
        obj4.print();
    else
        cout <<"obj4 handle is not valid" << endl;
    */
    return 0;
}