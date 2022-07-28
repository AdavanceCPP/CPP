#include<iostream>
#include<string>
using namespace std;

/*
* An enumerated type that represents the type of the variable currently
* being stored in the Variant.
*/
enum VariantType{IntType, FloatType,DoubleType,InvalidType};
//----------------------------------------
class Variant
{
	friend ostream& operator <<(ostream &print, Variant &v);
public:
	Variant();
	Variant(int val);
	Variant(float val);
	Variant(double val);
	~Variant();
	VariantType GetType() const;
	int AsInt();
	const int AsInt() const;
	float AsFloat();
	const float AsFloat() const;
	double AsDouble();
	const double AsDouble() const;
private:
	union VariantUnion
	{
		int intValue;
		float floatValue;
		double doubleValue;
	};
	VariantUnion value;
	VariantType type;
};

Variant::Variant() { type=InvalidType; }
Variant::Variant(int val) 
{ 
	cout <<"inside variant-int constructor" << endl;
	value.intValue = val;
	type = IntType;
}
Variant::Variant(float val) 
{ 
	value.floatValue = val;
	type = FloatType;
}
Variant::Variant(double val) 
{ 
	value.doubleValue = val;
	type = DoubleType;
}


Variant::~Variant()	{	}
VariantType Variant::GetType() const
{
	return type;
}
int Variant::AsInt()
{
	return value.intValue;
}
const int Variant::AsInt() const
{
	return value.intValue;
}

float Variant::AsFloat()
{
	return value.floatValue;
}
const float Variant::AsFloat() const
{
	return value.floatValue;
}
double Variant::AsDouble()
{
	return value.doubleValue;
}
const double Variant::AsDouble() const
{
	return value.doubleValue;
}

ostream& operator <<(ostream &print, Variant &v)
{
	switch(v.GetType())
	{
	case IntType:
		cout << v.AsInt() <<endl;
		break;
	case FloatType:
		cout << v.AsFloat() << endl;
		break;
	case DoubleType:
		cout << v.AsDouble() << endl;
		break;
	default:
		cout <<"Invalid Type" << endl;
	}
	return print;
}

void main()
{

	Variant v1;
	cout << v1 << endl;
	v1=200;
	cout << v1 << endl;
	v1=12.34f;
	cout << v1 << endl;
	v1 = 56.78;
	cout << v1 << endl;
}