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

		cout << "\t \t \t \t \t ���� <<��������>>\n\n\n";
		cout << "   �������� ������� ���������� ���������:       \n";
		cout << "___________________________________________" << endl;
		cout << "___________________________________________" << endl;
		cout << "||������ ����(1)                         ||\n";
		cout << "||_______________________________________||" << endl;
		cout << "||���������� ���������(2)                ||\n";
		cout << "||_______________________________________||" << endl;
		cout << "___________________________________________" << endl;
		cout << "\n";
		cout << "��� ������� ���������� ���������: " << endl;
		cout << "______________________________________" << endl;
		cin >> n;


		
		switch (n) {

		case '1': {
			cout << "||��� ����������: ||\n";
			cin >> ostatoc;
			system("cls");
			cout << "||    ��������� ����� �� ������� ����������    ||\n";
			cout << "_________________________________________________/\n";
			cout << "|| ��� ����� ������������� ��������: ������, ������ � ������        ||\n";
			system("cls");

		
			int otvetfor = 1;
			int iscomoe = ostatoc / 2, kolvo = 0, chast = ostatoc / 2;
			while (otvetfor != 2) {
				cout << "     ���� �����.....? " << iscomoe << "\n";
				cout << "  ������(1)                        \n";
				cout << "  ������(2)                        \n";
				cout << "  ������(3)                        \n";
				cin >> otvet;
				system("cls");
				while (otvet > '3' || otvet < '1') {
					cout << "           �� ����������� ����� �����!             \n";

					cout << "     ���� �����.....? " << iscomoe << "\n";
					cout << " ������(1)                        \n";
					cout << " ������(2)                        \n";
					cout << " ������(3)                       \n";
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
			cout << "||                    ����                       ||\n";
			cout << "_________________________________________________" << endl;
			cout << "_________________________________________________" << endl;
			cout << " ���� �����: " << iscomoe << "\n";
			cout << " ���-�� �������: " << kolvo << " ������� \n";
			cout << " ������������ ���-�� �������:  " << max_shag << "\n";
			system("pause");
			system("cls");
			break;
		}

				//������� 2 ����� �� ���������
		case '2': {
			system("cls");
			cout << "               �����              \n";
			cout << "                                                   \n";
			return 0;
			break;
		}

				//�������� ������� ���������� 
		default: {
			cout << "�� ����� ������������ ������� ����������\t!!!!!!!\n";
			cout << "���������,� ���� ���������� � ����\t\t!!!!!!!\n";
			break;
		}
		}
	}

	return 0;
}