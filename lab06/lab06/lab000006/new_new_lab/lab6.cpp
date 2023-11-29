#include "Hash_Twin_Chain.h"
#include <iostream>
#include <windows.h>
#include <tchar.h>
#include "Lists.h"
#include <chrono>
#include <stdlib.h>

#define INT_MAX 32767
#define MAXLENGTH 100
using namespace std;


struct AAA
{
	int key;
	const char* mas;
	AAA(int k, const char* z)
	{
		key = k;
		mas = z;
	}
	AAA()
	{
		key = 0;
		mas = "";
	}
};
//-------------------------------
int hf(void* d)
{
	AAA* f = (AAA*)d;
	return f->key;
}
//-------------------------------
void AAA_print(listx::Element* e)
{
	std::cout << ((AAA*)e->data)->key << '-' << ((AAA*)e->data)->mas << " / ";
}
//-------------------------------

int main()
{
	setlocale(LC_ALL, "rus");
	SetConsoleOutputCP(1251);
	SetConsoleCP(1251);
	srand(time(0));
	int current_size = 0;
	cout << "Введите размер таблицы: ";
	cin >> current_size;
	hashTC::Object H = hashTC::create(current_size, hf);
	int choice;
	int k;
	for (;;)
	{
		cout << "Вывести таблицу(1)" << endl;
		cout << "Добавить элемент(2)" << endl;
		cout << "Удалить элемент(3)" << endl;
		cout << "Найти элемент(4)" << endl;
		cin >> choice;
		switch (choice)
		{
		case 0:  exit(0);
		case 2: {	  AAA* a = new AAA;
			char* str = new char[MAXLENGTH];
			char* str_num = new char[MAXLENGTH];
			cout << "Введите номер абонента : ";
			cin.ignore();
			cin.getline(str_num, 100);
			bool uncor = true;
				for (int i = 0; i < strlen(str_num); i++)
				{
					if (str_num[i] < '0' || str_num[i] > '9')
					{
						cout << "Неверно указан номер, введите другое значение:\n";
						uncor = false;
						break;
					}
				}
				if (!uncor)
					break;
				if (strlen(str_num) > 6)
				{
					cout << "Неверно указан номер, введите другое значение:\n";
					break;
				}
				k = atoi(str_num);
				if (k > INT_MAX || k < 0)
				{
					cout << "Неверно указан номер, введите другое значение:\n";
					break;
				}
				a->key = k;
				cout << "Введите имя абонента: ";
				cin.getline(str, 100, '\n');
				a->mas = str;
				H.insert(a);
				cout << endl;
			}
			  break;
		case 1: H.Scan();
			break;
		case 3: {	  AAA* b = new AAA;
			cout << "Введите номер абонента, которого хотите удалить: ";
			cin >> k;
			b->key = k;
			H.deleteByData(b);
		}
			  break;
		case 4: {AAA* c = new AAA;
			cout << "Введите номер абонента, для поиска: ";
			cin >> k;
			c->key = k;
			auto begin = std::chrono::high_resolution_clock::now();
			H.Scan1(c);
			auto end = std::chrono::high_resolution_clock::now();
			auto elapsed = std::chrono::duration_cast<std::chrono::microseconds>(end - begin);
			int long el = elapsed.count();
			std::cout << "Время поиска: " << el << " мкс" << "\n\n\n" << std::endl;
		}
			  break;
		}
	}
	return 0;
}
