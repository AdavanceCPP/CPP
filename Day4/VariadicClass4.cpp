#include<iostream>
using namespace std;
//POLICY DESIGN WITH VARIADIC CLASS TEMPLATE
class Flute
{
public:
	void playFlute()
	{
		cout << "playing flute" << endl;
	}
};

class Piano
{
public:
	void playPiano()
	{
		cout << "playing flute" << endl;
	}
};

class Drums
{
public:
	void playDrums()
	{
		cout << "playing Drums" << endl;
	}
};

class Guitar
{
public:
	void playGuitar()
	{
		cout << "playing Guitar" << endl;
	}
};

class Violin
{
public:
	void playViolin()
	{
		cout << "playing Violin" << endl;
	}
};

/*
	- A variadic class template facilitating multiple inheritance is a
	  good candidate for those objects belonging to classes having different
	  method names & signature.
	- Derives from its own parameter pack
*/
//Derive from the parameter pack
template<typename... INSTRUMENTS> class Music :public INSTRUMENTS... {   };

int main()
{
	Music<Flute, Drums,Piano> obj1;
	/*
	obj1.playFlute();
	obj1.playDrums();
	obj1.playPiano();*/
	cout << "----------------" << endl;
	Music<Flute> obj2;
	
	//obj2.playFlute();
	cout << "----------------" << endl;
	Music<Guitar, Drums,Violin> obj3;
	
	//obj3.playDrums();
	//obj3.playGuitar();
	//obj3.playViolin();
	cout << "----------------" << endl;
	//...
	return 0;
}