#include <iostream>
#include <Windows.h>
#include <cstdlib>
#include <math.h>
using namespace std;

void bubble(int* const arr, int n);
void vstav();
void vibor();
void fast();

int main() {
	setlocale(LC_ALL, "Russian");
	clock_t start_bubble, start_vstav, start_vibor, start_fasr;
	clock_t end_bubble, end_vstav, end_vibor, end_fast;
	double itog_bubble, itog_vstav, itog_vibor, itog_fast;

	cout << "1 - запуск\n2 - выход\n";
	int n;
	cin >> n;
	switch (n) {
	case 1:
	{
		cout << "введите количество элементов массива\n";
		int size;
		cin >> size;
		cout << "__________________________________\n";
		//Генерация и заполнение случайными числами одномерного динамического массива
		int* arrA = new int[size];
		for (int i = 0; i < size; i++) {
			arrA[i] = rand() % 100;
		}
		//Вывод массива
		for (int i = 0; i < size; i++) {
			cout << arrA[i] << "\n";
		}
		//Созжание массивов B,C,D,E и копирование значений из массива A в массив B,C,D,E
		int* arrB = new int[size];
		int* arrC = new int[size];
		int* arrD = new int[size];
		int* arrE = new int[size];
		for (int i = 0; i < size; i++) {
			arrB[i] = arrA[i];
			arrC[i] = arrA[i];
			arrD[i] = arrA[i];
			arrE[i] = arrA[i];
		}
		//Время
		unsigned int start_time, end_time;

		cout << "выберите метод сортировки....\n1 - пузырьковая\n2-вставкой\n3-выбором\n4-быстрая\n";
		int k;
		cin >> k;
		switch (k) {
		case 1: {
			//Пузырьковская сортировка
			start_time = clock();
			bubble(arrB, size);
			end_time = clock();
			unsigned int bubble_sort_time = (end_time + start_time) / 2;
			cout << "\nОтсортированный пузырём массив:\n";
			for (int i = 0; i < size; i++) {
				cout << arrB[i] << "\n";
			}
			cout << "\nВремя сортировки пузрёёём:" << bubble_sort_time << "мс.\n";
			start_time = 0;
			end_time = 0;
		};
		}
	};

	}
}
