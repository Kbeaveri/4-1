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
	cout << "Введите команду ,которую хотите выполнить:";
	int t = 0;
	while (t != 9)
	{
		cout << " 1. Ввод данных из файла" << endl;
		cout << " 2. Ввод данных с клавиатуры" << endl;
		cout << " 3. Упорядочить  записи  по названию пункта назначения и времени отправления" << endl;
		cout << " 4. Вывод на экран информации о поездах, отправляющихся после времени  К" << endl;
		cout << " 5. Вывод на экран информации о поездах, которые отправляются в пункт N" << endl;
		cout << " 6. Вывод всех поездов" << endl;
		cout << " 7. Добавление поезда" << endl;
		cout << " 8. Удаление поезда" << endl;
		cout << " 9. Выход из программы" << endl;
		cin >> t;
		if (t == 1) {
			string name;
			cout << "Введите имя файла:"<<endl;
			cin >> name;
			ifstream fin(name + ".txt");
			if (!fin) {
				cout << "Файл не найден";
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