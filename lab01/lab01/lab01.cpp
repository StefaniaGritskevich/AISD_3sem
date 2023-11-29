#include <iostream>
#include <ctime>
using namespace std;

int main() {

	setlocale(LC_ALL, "russian");

	int n;
	//Вычисление n-го числа последовательности Фибоначчи с помощью цикла
	cout << "Введите N числа последовательности Фибоначчи: ";
	cin >> n;
	cout << "\n";
	 int start_time = clock();
	unsigned long long int a = 0, b = 1, c;
	if (n <= 2) {
		if (n == 0) {
			cout << n << " элемент последовательности Фибоначчи равен " << a << "\n\n\n";
		}
		if (n == 1) {
			cout << n << " элемент последовательности Фибоначчи равен " << b << "\n\n\n";
		}
		if (n == 2) {
			cout << n - 1 << " элемент последовательности Фибоначчи равен " << b << "\n\n\n";
		}
	}
	else {
		for (int i = 2; i <= n; i++) {
			c = a + b;
			a = b;
			b = c;
		}
		cout << n << " элемент последовательности Фибоначчи равен " << b << "\n\n";
	}
	int end_time = clock();
	 int final_time = (end_time - start_time) / 1000;
	cout << "Время выполнения : " << (final_time ) / 60 << "м. " << final_time << "c. " << (end_time - start_time) % 1000 << "мс. " << endl;
	return 0;
}

