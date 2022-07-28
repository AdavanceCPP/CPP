#include<iostream>
using namespace std;

/*
* An enumerated type that represents the type of the variable currently
* being stored in the Variant.
*/
enum VariantType{IntType, StringType,InvalidType};
//----------------------------------------
class Variant
{
	friend ostream& operator <<(ostream &print, const Variant &v);
public:
	Variant();
	Variant(int val);
	Variant(char* val);
	~Variant();
	VariantType GetType() const;
	int AsInt();
	const int AsInt() const;
	char* AsString();
	const char* AsString() const;
private:
	union VariantUnion
	{
		int intValue;
		char* stringValue;
	};
	VariantUnion value;
	VariantType type;
};

Variant::Variant() { type=InvalidType; }
Variant::Variant(int val) 
{ 
	value.intValue = val;
	type = IntType;
}
Variant::Variant(char* val) 
{ 
	value.stringValue = val;
	type = StringType;
}

Variant::~Variant()	{ }
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

char* Variant::AsString()
{
	return value.stringValue;
}
const char* Variant::AsString() const
{
	return value.stringValue;
}

ostream& operator <<(ostream &print, const Variant &v)
{
	switch(v.GetType())
	{
	case IntType:
		cout << v.AsInt() <<endl;
		break;
	case StringType:
		cout << v.AsString() << endl;
		break;
	default:
		cout <<"Invalid Type" << endl;
	}
	return print;
}
void main()
{

	const Variant v1(200);
	cout << v1 << endl;
	Variant v2="hello world";
	cout << v2 << endl;
}