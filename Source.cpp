#include <iostream>
#include "List.h"
#include "AEROFLOT.h"
#include <fstream>
#include <string>



using namespace std;



int main()
{
	List <AEROFLOT> arr;
	setlocale(LC_ALL, "Russian");
	cout << "������� ������� ,������� ������ ���������:"<<endl;
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
					char type1;
					fin >> number1 >> city1 >> type1;
					arr.push_sort(AEROFLOT(number1, city1, type1));
					cout << endl << endl << endl;
					arr.printAll();
				}
			}
		}
		if (t == 2) {
			int n;
			cin >> n;
			for (int i = 0; i < n; i++) {
				int number1;
				string city1;
				char type1;
				cin >> number1 >> city1 >> type1;
				arr.push_sort(AEROFLOT(number1, city1, type1));
			}
		}
		if (t == 3) {
			arr.printAll();
		}
		if (t == 4) {
			arr.delet(1);
			arr.printAll();
		}
	}
}