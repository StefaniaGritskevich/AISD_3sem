#include <iostream>
#include <Windows.h>
#include <cstdlib>
#include <math.h>
using namespace std;


HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
int main() {

	setlocale(LC_ALL, "Russian");
	SetConsoleTextAttribute(hStdOut, FOREGROUND_RED | FOREGROUND_INTENSITY);
	srand(unsigned(time(NULL)) * 100 * 100 * 100 * 100);

	int menufor = 1;

	while (menufor != 0) {

		char n, otvet;
		int ostatoc;

		cout << "\t \t \t \t \t ИГРА <<УГАДАЙКА>>\n\n\n";
		cout << "   Выберите вариант выполнения программы:       \n";
		cout << "___________________________________________" << endl;
		cout << "___________________________________________" << endl;
		cout << "||Начать игру(1)                         ||\n";
		cout << "||_______________________________________||" << endl;
		cout << "||Завершение программы(2)                ||\n";
		cout << "||_______________________________________||" << endl;
		cout << "___________________________________________" << endl;
		cout << "\n";
		cout << "Ваш вариант выполнения программы: " << endl;
		cout << "______________________________________" << endl;
		cin >> n;


		
		switch (n) {

		case '1': {
			cout << "||Ваш промежуток: ||\n";
			cin >> ostatoc;
			system("cls");
			cout << "||    Загадайте число из данного промежутка    ||\n";
			cout << "_________________________________________________/\n";
			cout << "|| Вам будут предоставлены варианты: меньше, больше и угадал        ||\n";
			system("cls");

		
			int otvetfor = 1;
			int iscomoe = ostatoc / 2, kolvo = 0, chast = ostatoc / 2;
			while (otvetfor != 2) {
				cout << "     Ваше число.....? " << iscomoe << "\n";
				cout << "  Меньше(1)                        \n";
				cout << "  Больше(2)                        \n";
				cout << "  Угадал(3)                        \n";
				cin >> otvet;
				system("cls");
				while (otvet > '3' || otvet < '1') {
					cout << "           Вы некорректно ввели ответ!             \n";

					cout << "     Ваше число.....? " << iscomoe << "\n";
					cout << " Меньше(1)                        \n";
					cout << " Больше(2)                        \n";
					cout << " Угадал(3)                       \n";
					cin >> otvet;
					system("cls");
				}

				kolvo = kolvo++;
				if (otvet == '1') {
					if (kolvo == 1) {
						iscomoe = chast - chast / 2;
						chast = chast / 2;
					}
					else {
						iscomoe = iscomoe - chast;
					}
					if (chast == 0) {
						iscomoe = iscomoe - 1;
					}
				}
				if (otvet == '2') {
					if (kolvo == 1) {
						iscomoe = chast + chast / 2;
						chast = chast / 2;

					}
					else {
						iscomoe = iscomoe + chast;
					}
					if (chast == 0) {
						iscomoe = iscomoe + 1;
					}
				}
				if (otvet == '3') {
					otvetfor = 2;
				}
				chast = chast / 2;
			}
			system("cls");

			int max_shag = 0, gread = ostatoc;
			while (gread != 0) {
				gread = gread / 2;
				max_shag = max_shag + 1;
			}
			cout << "_________________________________________________" << endl;
			cout << "_________________________________________________" << endl;
			cout << "||                    Итог                       ||\n";
			cout << "_________________________________________________" << endl;
			cout << "_________________________________________________" << endl;
			cout << " Ваше число: " << iscomoe << "\n";
			cout << " Кол-во попыток: " << kolvo << " попыток \n";
			cout << " Максимальное кол-во попыток:  " << max_shag << "\n";
			system("pause");
			system("cls");
			break;
		}

				//Вариант 2 Выход из программы
		case '2': {
			system("cls");
			cout << "               Конец              \n";
			cout << "                                                   \n";
			return 0;
			break;
		}

				//Невернай вариант выполнения 
		default: {
			cout << "Вы ввели некорректный вариант выполнения\t!!!!!!!\n";
			cout << "программы,и были возвращены в меню\t\t!!!!!!!\n";
			break;
		}
		}
	}

	return 0;
}