#include <string>;
#include <typeinfo>;

using namespace std;

class AEROFLOT
{
public:
	int number;
	string city;
	char type;
	bool operator < (const AEROFLOT& p) {
		if (number < p.number) {
			return 1;
		}
		else {
			return 0;
		}
	}
	bool operator == (const int& a) {
		return (a == number);
	}
	bool operator == (const char& a) {
		return (a == type);
	}
	bool operator == (const string& a) {
		return (a == city);
	}
	friend ostream& operator<<(ostream& os, const AEROFLOT& dt);
	void Print_All();
	AEROFLOT(int, string, char);
};






