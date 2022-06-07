#include <iostream>
#include "List.h"
#include "AEROFLOT.h"
#include <fstream>
#include <string>



using namespace std;

void sort(List <AEROFLOT>& arr) {
	for (auto it = arr.begin(); it != arr.end(); ++it) {
		AEROFLOT t = *it;
		for (auto it2 = arr.begin(); it2 != arr.end(); ++it2) {
			AEROFLOT t1 = *it2;
			if (t > t1) {
				AEROFLOT tmp = t;
				t = t1;
				t1 = tmp;
			}
		}
	}
}


int main()
{
	List <AEROFLOT> arr;
	setlocale(LC_ALL, "Russian");
	cout << "������� ������� ,������� ������ ���������:";
	int t = 0;
	while (t != 9)
	{
		cout << " 1. ���� ������ �� �����" << endl;
		cout << " 2. ���� ������ � ����������" << endl;
		cout << " 3. �����������  ������  �� �������� ������ ���������� � ������� �����������" << endl;
		cout << " 4. ����� �� ����� ���������� � �������, �������������� ����� �������  �" << endl;
		cout << " 5. ����� �� ����� ���������� � �������, ������� ������������ � ����� N" << endl;
		cout << " 6. ����� ���� �������" << endl;
		cout << " 7. ���������� ������" << endl;
		cout << " 8. �������� ������" << endl;
		cout << " 9. ����� �� ���������" << endl;
		cin >> t;
		if (t == 1) {
			string name;
			cout << "������� ��� �����:"<<endl;
			cin >> name;
			ifstream fin(name + ".txt");
			if (!fin) {
				cout << "���� �� ������";
			}
			else {
				int n;
				fin >> n;
				for (int i = 0; i < n; i++) {
					int number1;
					string city1;
					string type1;
					fin >> number1 >> city1 >> type1;
					arr.push_back(AEROFLOT(number1, city1, type1));
				}
			}
			sort(arr);
			arr.printAll();
		}
	}
}