#include<iostream>
#include<vector>
using namespace std;

/*
* An enumerated type that represents the type of the variable currently
* being stored in the Variant.
*/
enum VariantType{FirstType, SecondType,ThirdType,InvalidType};
//----------------------------------------
template<typename T1, typename T2, typename T3> class Variant
{
	template<typename T1, typename T2, typename T3> 
	friend ostream& operator << <T1,T2,T3>(ostream &print, Variant<T1,T2,T3> &v);
public:
	Variant();
	Variant(T1 val);
	Variant(T2 val);
	Variant(T3 val);
	~Variant();
	VariantType GetType() const;
	T1 AsT1();
	const T1 AsT1() const;
	T2 AsT2();
	const T2 AsT2() const;
	T3 AsT3();
	const T3 AsT3() const;
private:
	union VariantUnion
	{
		T1 Value1;
		T2 Value2;
		T3 Value3;
	};
	VariantUnion value;
	VariantType type;
};

template<typename T1, typename T2, typename T3> Variant<T1,T2,T3>::Variant() 
{ type=InvalidType; }

template<typename T1, typename T2, typename T3> Variant<T1,T2,T3>::Variant(T1 val) 
{ 
	value.Value1 = val;
	type = FirstType;
}
template<typename T1, typename T2, typename T3> Variant<T1,T2,T3>::Variant(T2 val) 
{ 
	value.Value2 = val;
	type = SecondType;
}
template<typename T1, typename T2, typename T3> Variant<T1,T2,T3>::Variant(T3 val) 
{ 
	value.Value3 = val;
	type = ThirdType;
}


template<typename T1, typename T2, typename T3> Variant<T1,T2,T3>::~Variant()	{	}
template<typename T1, typename T2, typename T3> 
VariantType Variant<T1, T2, T3>::GetType() const
{
	return type;
}

template<typename T1, typename T2, typename T3> T1 Variant<T1,T2,T3>::AsT1()
{
	return value.Value1;
}
template<typename T1, typename T2, typename T3> const T1 Variant<T1,T2,T3>::AsT1() const
{
	return value.Value2;
}

template<typename T1, typename T2, typename T3> T2 Variant<T1,T2,T3>::AsT2()
{
	return value.Value2;
}
template<typename T1, typename T2, typename T3> const T2 Variant<T1,T2,T3>::AsT2() const
{
	return value.Value2;
}

template<typename T1, typename T2, typename T3> T3 Variant<T1,T2,T3>::AsT3()
{
	return value.Value3;
}
template<typename T1, typename T2, typename T3> const T3 Variant<T1,T2,T3>::AsT3() const
{
	return value.Value3;
}

template<typename T1, typename T2, typename T3>
ostream& operator <<(ostream &print, Variant<T1,T2,T3> &v)
{
	switch(v.GetType())
	{
	case FirstType:
		cout << v.AsT1() <<endl;
		break;
	case SecondType:
		cout << v.AsT2() << endl;
		break;
	case ThirdType:
		cout << v.AsT3() << endl;
		break;
	default:
		cout <<"Invalid Type" << endl;
	}
	return print;
}
//------------------------
class CA
{
public:
	friend ostream& operator <<(ostream &print, CA &x);
	void print() {cout <<"CA-print" << endl; }
};
ostream& operator <<(ostream &print, CA &x)
{
	x.print();
	return print;
}
//---------------------------
class CB
{
public:
	friend ostream& operator <<(ostream &print, CB &x);
	void print() {cout <<"CB-print" << endl; }
};
ostream& operator <<(ostream &print, CB &x)
{
	x.print();
	return print;
}
//---------------------------
class CC
{
public:
	friend ostream& operator <<(ostream &print, CC &x);
	void print() {cout <<"CC-print" << endl; }
};
ostream& operator <<(ostream &print, CC &x)
{
	x.print();
	return print;
}
//-----------------------------
void main()
{
	Variant<int,float,CA> v1;
	v1=200;
	cout << v1 << endl;
	v1=23.12f;
	cout << v1 << endl;
	CA obj1;
	v1=obj1;
	cout << v1 << endl;
	//------------------------------
	Variant<CA,CB,CC> v2;
	CB obj2;
	CC obj3;
	v2=obj1;
	cout << v2 << endl;
	v2=obj2;
	cout << v2 << endl;
	v2=obj3;
	cout << v2 << endl;	
}