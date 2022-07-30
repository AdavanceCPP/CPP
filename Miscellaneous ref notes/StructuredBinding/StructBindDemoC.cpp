#include<iostream>
#include<string>
#include<tuple>

using namespace std;

/*
	- A custom class providing the client or class consumer with
	  "structured binding" Interface for select data member's
*/

namespace CUSTOM
{
	class Data
	{
	private:
		int id = 0;
		string name = "";
		double score = 0.0; //not to be exposed
	public:
		Data() = default;
		Data(int x, string&& s, double y) :id(x), name(move(s)), score(y) {}
		int GetId() const { return this->id; }
		string GetName() const { return this->name; }
		int& GetId()  { return this->id; }
		string& GetName()  { return this->name; }
	};

	//Interface functions....
	template<size_t INDEX> auto get(const Data& x) {}
	template<> auto get<0>(const Data& x) { return x.GetId(); }
	template<> auto get<1>(const Data& x) { return x.GetName(); }

	template<size_t INDEX> auto& get(Data& x) {}
	template<> auto& get<0>(Data& x) { return x.GetId(); }
	template<> auto& get<1>(Data& x) { return x.GetName(); }
}

namespace std
{
	template<> struct tuple_size<CUSTOM::Data> :std::integral_constant<size_t, 2> {};
	template<> struct tuple_element<0, CUSTOM::Data> { using type = int; };
	template<> struct tuple_element<1, CUSTOM::Data> { using type = std::string; };
}
//***class consumer****

int main()
{
	using namespace CUSTOM;
	Data obj1{ 100,"John",67.5 }, obj2{ 300,"bjarne",89.21 };
	auto [id, name] = obj1;
	cout << "id:" << id << endl;
	cout << "name:" << name << endl;
	id = 200;
	cout << "After id=200, id:" << id << ",and obj1.id=" << obj1.GetId() << endl;
	cout << "-----------------" << endl;
	auto& [id_, name_] = obj2;
	cout << "id_:" << id_ << endl;
	cout << "name_:" << name_ << endl;
	id_ = 200;
	cout << "After id_=200, id_:" << id << ",and obj2.id=" << obj2.GetId() << endl;
	return 0;
}