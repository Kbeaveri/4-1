#include <iostream>
#include "List.h"
#include "AEROFLOT.h"
#include <fstream>
#include <string>



using namespace std;

//void find(List <AEROFLOT> &arr,string city,int n) {
//	for (auto i = arr.begin(); i !=arr.end(); i++) {
//		
//	}
//}

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
		cout << " 3. ����� �� ����� ������� ������ �  ������� ����������, ������������� ���������� ���� �." << endl;
		cout << " 4. ����� �� ����� ����� ���������, ������� ��������� �����  T ������ � ����� ���������� �." << endl;
		cout << " 5. �������� ��������" << endl;
		cout << " 6. ����� ���� �������" << endl; 
		cout << " 7. ���������� ������" << endl;
		cout << " 8. ��������������� ������� " << endl;
		cout << " 9. ����� �� ���������" << endl;
		cin >> t;
		int n;
		if (t == 1) {
			if (!arr.empty()) {
				arr.~List();
				List <AEROFLOT> arr;
			}
			string name;
			cout << "������� ��� �����:"<<endl;
			cin >> name;
			ifstream fin(name + ".txt");
			if (!fin) {
				cout << "���� �� ������";
			}
			else {
				fin >> n;
				for (int i = 0; i < n; i++) {
					int number1;
					string city1;
					string type1;
					fin >> number1 >> city1 >> type1;
					arr.push_sort(AEROFLOT(number1, city1, type1));
				}
			}
		}
		if (t == 2) {
			if (arr.empty()) {
				arr.~List();
				List <AEROFLOT> arr;
			}
			cin >> n;
			for (int i = 0; i < n; i++) {
				int number1;
				string city1;
				string type1;
				cin >> number1 >> city1 >> type1;
				arr.push_sort(AEROFLOT(number1, city1, type1));
			}
		}
		if (t == 3) {
			cout << "������� �������� ��������";
			string name;
			cin >> name;
			AEROFLOT p(0,"af",name);
			arr.Cout_find(p);

		}
		if (t == 4) {
			cout << "������� �������� � ����������";
			int kol;
			string name;
			cin >> kol >> name;
			arr.find(kol, name);
		}
		if (t == 5) {
			cout << "������� ����� �������� ������� ������ �������";
			int a;
			cin >> a;
			arr.delet(a-1);
		}
		if (t == 6) {
			arr.printAll();
		}
		if (t == 7) {
			cout << "������� ������";
			int number1;
			string city1;
			string type1;
			cin >> number1 >> city1 >> type1;
			arr.push_sort(AEROFLOT(number1, city1, type1));
		}
		if (t == 8) {
			cout << "������� ����� �������� ������� ������ ���������������";
			int a;
			cin >> a;
			cout << "������� ������";
			int number1;
			string city1;
			string type1;
			cin >> number1 >> city1 >> type1;
			arr.edit(AEROFLOT(number1, city1, type1),a-1);
		}
	}
}