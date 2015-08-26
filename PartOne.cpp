#include<iostream>
#include<string.h>
using namespace std;

//Points Covered:
//public and private members
//Static data and method
//this pointer
//constructor, copy constructor, destructor

enum Grain{ wheat, rye, corn, barley };

class Whiskey{
public:
	int age;
	double alcoholByVolume;
	string manufacturer;
	string name;
	static int numberOfKnownWhiskeys;
	static void printCountOfKnownWhiskeys();
	Whiskey(int age, double abv, string manufacturer, string name){
		this->age = age;
		this->alcoholByVolume = abv;
		this->manufacturer = manufacturer;
		this->name = name;
		numberOfKnownWhiskeys ++;
	}

	Whiskey(const Whiskey &wh){
		this->age = wh.age;
		this->manufacturer = wh.manufacturer;
		this->name = wh.name;
		this->alcoholByVolume = wh.alcoholByVolume;
		setGrain(wh.grain);
	}

	~Whiskey(void){
		cout << "The object is being destroyed" << endl;
	}

	void setGrain(int grain){
		this->grain = grain;
	}

private:
	int grain;
};

int Whiskey:: numberOfKnownWhiskeys = 0;

void printCountOfKnownWhiskeys(){
	cout << "Known Whiskeys : " << Whiskey::numberOfKnownWhiskeys << endl;
}


int main(){
	cout << Whiskey::numberOfKnownWhiskeys << endl;
	Whiskey bd_tgr(12, 42.8, "United Spirits Ltd.", "Black Dog: Triple Gold Reserve");
	bd_tgr.setGrain(barley);
	cout << Whiskey::numberOfKnownWhiskeys << endl;
	Whiskey temp(bd_tgr);
	return 0;
}
