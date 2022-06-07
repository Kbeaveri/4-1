#include "AEROFLOT.h"
#include <iostream>;


AEROFLOT::AEROFLOT(int number, string city, string type) {
	this->number = number;
	this->city = city;
	this->type = type;
}


ostream& operator<<(ostream& os, const AEROFLOT& dt)
{
	os << dt.city << ' ' << dt.number << ' ' << dt.type;
	return os;
}


void AEROFLOT::Print_All() {
	cout << number << " " << city << " " << type << endl;
}