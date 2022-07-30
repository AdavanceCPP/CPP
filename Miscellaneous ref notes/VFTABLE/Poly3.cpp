#include<iostream>
using namespace std;
#pragma pack(1)
/*
    - Introduce a layer class whose sole purpose is to only act as a BASE kind.
    - This class is also likely to act as a FRAME-WORK for the derived ones
    - An instance of this class shall not be permitted, for the reason this class
      is also termed as a GENERALIZED class.
*/
class shape
{
protected:
    //void *vfptr;   added by the compiler as the first data-member
public:
     /*
        shape():vfptr(&shape::VFTABLE)
        {
            //A default constructor introduced by the compiler
        }
     */
    //virtual member functions or OVER-RIDABLE methods
    virtual void draw()=0;   //pure virtual function
    virtual ~shape(){ }    
};

class circle:public shape    // circle IS-A shape
{
private:
	int radius;
public:
                //  [ instructions added by the compiler, while compiling ]
	circle(int x=0):/* shape(), vfptr(&circle::VFTABLE),   */ radius(x)
    { cout <<"Circle constructor" << endl; }
    
    //OVER-RIDING methods
	void draw(){ cout <<"circle drawn" << endl; }
	~circle(){ cout <<"Circle destructor" << endl;}
};

class rectangle :public shape
{
private:
	int length, breadth;
public:
	rectangle(int x=0, int y=0):/* shape(), vfptr(&rectangle::VFTABLE), */length(x), breadth(y) 
    { cout <<"rectangle constructor" << endl; }
	//OVER-RIDING methods
    void draw(){ cout <<"rectangle drawn" << endl; }
	~rectangle(){ cout <<"rectangle destructor" << endl;}
};

class triangle :public shape
{
private:
	int base, height;
public:
	triangle(int x=0, int y=0):base(x), height(y) 
    { cout <<"triangle constructor" << endl; }
	//OVER-RIDING methods
    void draw(){ cout <<"triangle drawn" << endl; }
	~triangle(){ cout <<"triangle destructor" << endl;}
};
//A new type adds up

class polygon:public shape
{
private:
  int x;
public:
    polygon(int y):x(y){cout <<"polygon constructor..." << endl;}
    void draw(){cout <<"polygon drawn..." << endl;}
    ~polygon(){cout <<"polygon destructor..." << endl;}
};


void graphics(shape *);

int main()
{
    //shape* p = new(nothrow) shape;
	cout <<"size of circle object " << sizeof(circle) << endl;
	cout <<"size of rectangle object " << sizeof(rectangle) << endl;
	cout <<"size of triangle object " << sizeof(triangle) << endl;
	circle *c = new(nothrow) circle;
	graphics(c);
	cout <<"-----------------------"<<endl;
	rectangle *r = new(nothrow) rectangle;
	graphics(r);
	cout <<"-----------------------"<<endl;
	triangle *t = new(nothrow) triangle;
	graphics(t);
    cout <<"-----------------------"<<endl;
    polygon *q = new(nothrow) polygon(100);
    graphics(q);

	return 0;
}

void graphics(shape* p)  //Programmed to the ABSTRACTION
{
	p->draw();
	//...
	delete p;
}