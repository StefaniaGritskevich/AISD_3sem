#include <iostream>

using namespace std;

int main() {

	setlocale(LC_ALL, "russian");

	int n, fibonachi(int);
	//Вычисление n-го числа последовательности Фибоначчи с помощью рекурсии
	cout << "Введите номер числа последовательности Фибоначчи: ";
	cin >> n;
	unsigned int start_time = clock();
	unsigned long long int a = 0, b = 1;
	cout << "\n";
	cout << n << " элемент последовательности Фибоначчи равен " << fibonachi(n) << "\n\n\n";
	int end_time = clock();

	int final_time = (end_time - start_time)/1000;
	cout << "Время выполнения рекурсии: " << final_time/60 <<"м. "<< final_time << "c. " << (end_time - start_time) % 1000 << " мс.\n\n\n" << endl;
	return 0;
}
int fibonachi(int n) {
	if (n <= 2) {
		if (n == 0) {
			return 0;
		}
		if (n == 1) {
			return 1;
		}
	}
	return fibonachi(n - 1) + fibonachi(n - 2);
}