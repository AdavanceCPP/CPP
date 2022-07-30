#include<iostream>
#include<string>
#include<tuple>

using namespace std;
/*
	- A custom class providing the client or class consumer with
	  "structured binding" Interface for select data member's
*/
class Data
{
private:
	int S_id = 0;
	string S_name = "";
	double S_score = 0.0; //not to be exposed
public:
	Data() = default;
	Data(int x, string&& s, double y) :S_id(x), S_name(move(s)), S_score(y) {}
	decltype(auto) GetId() const
	{
		return make_tuple(this->S_id);
	}
	decltype(auto) GetName() const
	{
		return make_tuple(this->S_name);
	}
	decltype(auto) operator()() const
	{
		return std::make_tuple(S_id, S_name, S_score);
	}
};

//***class consumer****

int main()
{
	Data obj1{ 100,"John",67.5 };
	cout << "-------only id--------" << endl;
	const auto& [id] = obj1.GetId();
	cout << "Id:" << id << endl;
	cout << "-------only name--------" << endl;
	const auto& [name] = obj1.GetName();
	cout << "name:" << name << endl;
	cout << "-------all member's--------" << endl;
	const auto& [id_, name_, score_] = obj1();
	cout << "id:" << id_ << endl;
	cout << "name:" << name_ << endl;
	cout << "score:" << score_ << endl;
	return 0;
}