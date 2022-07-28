#include<iostream>
using namespace std;
/*
The foll: variadic class design is OK for any number of class types, but
it must be ensured all the class types should have a member function with the
same name and signature.
*/

template<typename... INSTRUMENT_TYPES> class Compose
{
public:
	void play_music() { cout <<"composing completed...." << endl;}
};

template<typename INSTRUMENT, typename ... INSTRUMENT_TYPES> 
           class Compose<INSTRUMENT, INSTRUMENT_TYPES...> : private Compose<INSTRUMENT_TYPES...>
{
private:
	INSTRUMENT object;
public:
	void play_music()
	{
		object.play();
		Compose<INSTRUMENT_TYPES...>::play_music();    //Compose<>::play_music();
	}
};

class Flute
{
public:
	void play()
	{
		cout << "playing flute" << endl;
	}
};

class Piano
{
public:
	void play()
	{
		cout << "playing Piano" << endl;
	}
};

class Drums
{
public:
	void play()
	{
		cout << "playing Drums" << endl;
	}
};

//Latest addition, and the consumer can directly consume without depending
//the variadic class library vendor for support.
class Guitar
{
public:
	void play()
	{
		cout << "playing Guitar" << endl;
	}
};

//****consumer code*****
int main()
{
	//Strategy-1 - only 2 instruments
	Compose<Flute, Drums> music1;
	music1.play_music();
	cout << "-------------------" << endl;
	//Strategy-2 - only 3 instruments
	Compose<Drums, Piano, Flute> music2;
	music2.play_music();
	cout << "-------------------" << endl;
	//Strategy-3 - only 1 instrument
	Compose<Flute> music3;
	music3.play_music();
	cout << "-------------------" << endl;
	//Strategy-4 - all 4 instrument
	Compose<Drums, Piano, Flute,Guitar> music4;
	music4.play_music();
	return 0;
}