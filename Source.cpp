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
	cout << "Введите команду ,которую хотите выполнить:"<<endl;
	int t = 0;
	while (t != 9)
	{
		cout << " 1. Ввод данных из файла" << endl;
		cout << " 2. Ввод данных с клавиатуры" << endl;
		cout << " 3. Вывод на экран номеров рейсов и  пунктов назначения, обслуживаемых самолетами типа К." << endl;
		cout << " 4. Вывод на экран типов самолетов, которые выполняют более  T рейсов в пункт назначения К." << endl;
		cout << " 5. Удаление элемента" << endl;
		cout << " 6. Вывод всех поездов" << endl; 
		cout << " 7. Добавление поезда" << endl;
		cout << " 8. Отредактировать элемент " << endl;
		cout << " 9. Выход из программы" << endl;
		cin >> t;
		int n;
		if (t == 1) {
			if (!arr.empty()) {
				arr.~List();
				List <AEROFLOT> arr;
			}
			string name;
			cout << "Введите имя файла:"<<endl;
			cin >> name;
			ifstream fin(name + ".txt");
			if (!fin) {
				cout << "Файл не найден";
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
			cout << "Введите название самолета";
			string name;
			cin >> name;
			AEROFLOT p(0,"af",name);
			arr.Cout_find(p);

		}
		if (t == 4) {
			cout << "Введите аэропорт и количество";
			int kol;
			string name;
			cin >> kol >> name;
			arr.find(kol, name);
		}
		if (t == 5) {
			cout << "Введите номер элемента который ъотите удалить";
			int a;
			cin >> a;
			arr.delet(a-1);
		}
		if (t == 6) {
			arr.printAll();
		}
		if (t == 7) {
			cout << "Введите данные";
			int number1;
			string city1;
			string type1;
			cin >> number1 >> city1 >> type1;
			arr.push_sort(AEROFLOT(number1, city1, type1));
		}
		if (t == 8) {
			cout << "Введите номер элемента который хотите отредактировать";
			int a;
			cin >> a;
			cout << "Введите данные";
			int number1;
			string city1;
			string type1;
			cin >> number1 >> city1 >> type1;
			arr.edit(AEROFLOT(number1, city1, type1),a-1);
		}
	}
}