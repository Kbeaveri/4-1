#include <string>;

using namespace std;

class AEROFLOT
{
public:
	int number;
	string city;
	string type;
	bool operator > (const AEROFLOT& p) {
		if (number > p.number) {
			return 1;
		}
		else {
			return 0;
		}
	}
	friend ostream& operator<<(ostream& os, const AEROFLOT& dt);
	void Print_All();
	AEROFLOT(int, string, string);
};






