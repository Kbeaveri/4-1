#include "AEROFLOT.h"
#include <iostream>;
#include <typeinfo>;

AEROFLOT::AEROFLOT(int number, string city, string type) {
	this->number = number;
	this->city = city;
	this->type = type;
}


ostream& operator<<(ostream& os, const AEROFLOT& dt)
{
	os << dt.number << ' ' << dt.city << ' ' << dt.type<<endl;
	return os;
}


void AEROFLOT::Print_All() {
	cout << number << " " << city << " " << type << endl;
}