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

	cout << "1 - ������\n2 - �����\n";
	int n;
	cin >> n;
	switch (n) {
	case 1:
	{
		cout << "������� ���������� ��������� �������\n";
		int size;
		cin >> size;
		cout << "__________________________________\n";
		//��������� � ���������� ���������� ������� ����������� ������������� �������
		int* arrA = new int[size];
		for (int i = 0; i < size; i++) {
			arrA[i] = rand() % 100;
		}
		//����� �������
		for (int i = 0; i < size; i++) {
			cout << arrA[i] << "\n";
		}
		//�������� �������� B,C,D,E � ����������� �������� �� ������� A � ������ B,C,D,E
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
		//�����
		unsigned int start_time, end_time;

		cout << "�������� ����� ����������....\n1 - �����������\n2-��������\n3-�������\n4-�������\n";
		int k;
		cin >> k;
		switch (k) {
		case 1: {
			//������������� ����������
			start_time = clock();
			bubble(arrB, size);
			end_time = clock();
			unsigned int bubble_sort_time = (end_time + start_time) / 2;
			cout << "\n��������������� ������ ������:\n";
			for (int i = 0; i < size; i++) {
				cout << arrB[i] << "\n";
			}
			cout << "\n����� ���������� ���𸸸�:" << bubble_sort_time << "��.\n";
			start_time = 0;
			end_time = 0;
		};
		}
	};

	}
}
