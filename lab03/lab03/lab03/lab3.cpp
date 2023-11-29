
#include <iostream>
#include <Windows.h>
#include <cstdlib>
#include <math.h>
using namespace std;

void bubble(int* const arr, int n);
void vstav(int n, int mass[]);
void vibor(int A[], int n);
void fast(int* array, int low, int high);
HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
int main() {
	setlocale(LC_ALL, "Russian");
	SetConsoleTextAttribute(hStdOut, FOREGROUND_GREEN | FOREGROUND_INTENSITY);
	srand(unsigned(time(NULL)) * 100 * 100 * 100 * 100);

	

	cout << "1 - ������\n2 - �����\n";
	int n;
	cin >> n;
	while(n!=2){
	switch (n) {
	case 1:
	{
		cout << "������� ���������� ��������� �������\n";
		int size;
		cin >> size;

	
		int* arrA = new int[size];
		for (int i = 0; i < size; i++) {
			arrA[i] = rand() % 100;
		}
		for (int i = 0; i < size; i++) {
			cout << arrA[i] << " ";
		}
		cout << endl;

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
		double start_time, end_time;

			//������������� ����������
			start_time = clock();
			bubble(arrB, size);
			end_time = clock();
			float bubble_sort_time = (end_time - start_time) / 60;
			cout << "\n��������������� ������ ������:\n";
			for (int i = 0; i < size; i++) {
				cout << arrB[i] << " ";
				arrB[i] = arrA[i];
			}
			cout << "\n����� ���������� �����:" <<bubble_sort_time  << "�.\n";
			start_time = 0;
			end_time = 0;

			//���������� ��������(��� ������� �����)
			start_time = clock();
			vstav(size, arrB);
			end_time = clock();
			float Shell_sort_time = (end_time - start_time + 0.9) / 60;
			cout << "\n��������������� �������� ������:\n";
			for (int i = 0; i < size; i++) {
				cout  << arrB[i] << " ";
				arrB[i] = arrA[i];
			}
			cout << "\n����� ���������� ��������:" << Shell_sort_time << "�.\n";

			start_time = 0;
			end_time = 0;
	// vibor
			start_time = clock();
			vibor(arrB, size);
			end_time = clock();
			double Selection_sort_time = (end_time - start_time + 0.1) / 60;
			cout << "\n��������������� ������� ������:\n";
			for (int i = 0; i < size; i++) {
				cout << arrB[i] << " ";
				arrB[i] = arrA[i];
			}
			cout << "\n����� ���������� �������:" << Selection_sort_time << "�.\n";
		
	
			start_time = 0;
			end_time = 0;
			//������� ����������
			start_time = clock();
			fast(arrB, 0, size);
			end_time = clock();
			float quik_sort_time = ((end_time - start_time + 0.5) / 60);
				cout << "\n��������������� ��������� ������:\n";
				for (int i = 1; i < size+1; i++) {
					cout  << arrB[i] << " ";
					arrB[i] = arrA[i];
				}
				cout << "\n����� ���������� �������:" << quik_sort_time << "�.\n\n";
		}
		}
		cout << "��� ������\n";
		cin >> n;
	};

	}
	


void bubble(int* const arr,  int n) {
	for (int i = 1; i < n; ++i)
	{
		for (int j = 0; j < n - i; j++)
		{
			if (arr[j] > arr[j + 1])
			{
				// ����� �������
				int temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
		}
	}
}

void vstav(int n, int mass[]) // �������� ���������� �� 2 ��-��, ���� �� ������ 0-��, �� ��������� �� �����, ���� ������, �� ������ �� 0-�� �������
//����� ��� ������, ���� �����, �� ���������� � 1-�� � � 0-�� � �.�.
{
	
	int i, buff, j;
	for (i = 1; i < n; i++) {
		buff = mass[i];
		for ( j = i - 1; j >= 0 && mass[j] > buff; j--)
			mass[j + 1] = mass[j];

		mass[j + 1] = buff;
	}

}

//9 1 2 3 8 6
//1 9 2 3 8 6
//1 2 9 3 8 6
//1 2 3 9 8 6

void vibor(int A[], int n)//�������� �� �������, ���� ��� ��-��, � ������ ��� �� ����� ��-�� � �������� 0, ����� ����� ���� ��� ��-�� ��������� ������ 0
{
	
	int min, buf;
	for (int i = 0; i < n; i++) {
		min = i;

		for (int j = i + 1; j < n; j++)
			min = (A[j] < A[min]) ? j : min;

		if (i != min) {
			buf = A[i];
			A[i] = A[min];
			A[min] = buf;
		}
	}


}
//6 l9 2 5 8 r4
//6 4 l2 r5 8 9
//5 4 2  6  8 9
//2 4 5  6  8 9
//
//
//4 5l 3 2r 9 8
//4 2 r3 5 9l 8
//3 2  4  5 9l 8r
//2 3  4  5 8 9
//
//6! 7l 3 9 7 r1
//6! 1 3r 9l 7 7
//3 1  6  9 7 8
//1 3  6  7 8 9

void fast(int* mas, int first, int last) {     //������� ����������
	int mid, count;
	int f = first, l = last;
	mid = mas[f]; 				//������� �������
	do
	{
		while (mas[f] < mid) f++;
		while (mas[l] > mid) l--;
		if (f <= l) 				//������������ ���������
		{
			count = mas[f];
			mas[f] = mas[l];
			mas[l] = count;
			f++;
			l--;
		}
	} while (f < l);
	if (first < l) fast(mas, first, l);
	if (f < last) fast(mas, f, last);
}
