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
    cout << "\t \t \t \t \t ИГРА <<УГАДАЙКА>>\n\n\n";
    float minedge = 0, maxedge, half, num;
    int n;
    bool flag = false;
    cout << "\t \t \t \tВведите пределы выбранного промежутка: ";
    cin >> maxedge;
    num = maxedge;
    system("cls");

    cout << "\t \t \t \t \tЗагадайте число\n";
    system("pause");

    system("cls");

    while ((minedge < maxedge - 1) && (flag != true)) {
        system("cls");
        half = ceil((minedge + maxedge) / 2);
        cout << "\t \t \t \t \tВы загадали " << (int)half << "?\n";
        cout << "1 - меньше\n";
        cout << "2 - больше\n";
        cout << "3 - угадал(а)\n";
        cin >> n;

        switch (n) {
        case 1:
            maxedge = half;
            break;
        case 2:
            if (half == num - 1) {
                cout << "\t \t \t \t \tВы загадали " << ++half << endl;
                exit(0);
            }
            else
                minedge = half;
            break;
        case 3:
            flag = true;
            break;
        default:
            cout << "\t \t \t \t \tНекорректный ввод\n";
            return -1;
        }
    }

    cout << "\t \t \t \t \tВы загадали " << half << endl;
    int i = -1;
    do {
        i++;
    } while (pow(2, i) <= num);

    cout << "\n\t \t \t \t \tМаксимальное количество шагов = " << i << endl;
    cout << num << endl;

    while (num > 1) {
        num = ceil(num / 2);
        cout << num << endl;
    }

    return 0;
}