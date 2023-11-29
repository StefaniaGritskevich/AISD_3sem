#include <iostream>
#include <Windows.h>
#include <cstdlib>
#include <math.h>

using namespace std;
HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);

int* bubble_sort(int* arr, int n_arr) {

    int temp = 0; //Временная   переменная

    for (int i = 0; i < n_arr - 1; i++) {
        for (int j = i + 1; j < n_arr; j++) {
            if (arr[i] > arr[j]) {
                temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }

    return arr;
}

int vin(int* arr, int size)
{
    int vins = 0;
    int nom = 0;
    for (int i = size - 1; i >= 0; i--)
    {
        if (nom == 3)
        {
            break;
        }
        if (arr[i] == arr[i - 1])
        {
            vins++;
        }
        if (arr[i] > arr[i - 1])
        {
            nom++;
            vins++;
        }
    }
    return vins;
}

int* bubble_sort_obr(int* arr, int n_arr) {

    int temp = 0; //Временная   переменная

    for (int i = n_arr - 1; i >= 0; i--) {
        for (int j = i - 1; j >= 0; j--) {
            if (arr[i] > arr[j]) {
                temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }

    return arr;
}



int main() {


    setlocale(LC_ALL, "rus");
    SetConsoleTextAttribute(hStdOut, FOREGROUND_GREEN | FOREGROUND_INTENSITY);
    srand(unsigned(time(NULL)) * 100 * 100 * 100 * 100);
    int forar = 1;
    while (forar != 0) {
        char n;
        system("cls");
        //Меню
    
        cout << " 1 - задача 1 \n";
        cout << " 2 - задача 2 \n";
        cout << "?: ";
        cin >> n;
        system("cls");

        //Варианты выполнения программы
        switch (n) {

            //Вариант 1 Игра 
        case '1': {

            int arr_n;
            cout << " Введите количество товаров\n";
            cin >> arr_n;
            system("cls");
            if (arr_n >= 10000)break;
            //Генерация и заполнение случайными числами одномерного динамического массива
            static int* arrA = new int[arr_n];
            for (int i = 0; i < arr_n; i++) {
                arrA[i] = rand() % 100;
            }
            cout << " Итого: \n";
            //Вывод массива
            for (int i = 0; i < arr_n; i++) {
                cout << arrA[i] << " ";
            }
            cout << endl;
          

            bubble_sort(arrA, arr_n);
           
            cout << "Отсортированный вариант: \n";
      
            for (int i = 0; i < arr_n; i++) {
                cout << arrA[i] << " ";
            }
           
            int maxsum = 0;
            int jfor = arr_n / 2;
            int jformin = arr_n / 2;
            if (arr_n % 2 != 1) {
                jfor = jfor - 1;
                jformin = jformin - 1;
            }
            static int* arrB = new int[arr_n];

            for (int i = 0; i < arr_n; i++) {
                if (i % 2 != 1) {
                    arrB[i] = arrA[jfor];
                    jfor++;
                    maxsum = maxsum + arrA[jfor];
                }
            }
            for (int i = arr_n - 1; i >= 0; i--) {
                if (i % 2 != 0) {
                    arrB[i] = arrA[jformin];
                    jformin--;
                }
            }
            cout << "\n\n";
            cout << "Чек: \n";
            //Вывод массива
            for (int i = 0; i < arr_n; i++) {
                cout << arrB[i] << " ";
            }
            cout << "\n";
            cout << "Сумма чека = " << maxsum << endl;
            system("pause");
            break;
        }
        case '2': {
            system("cls");


            int arr_n;
            cout << "Введите количество участников: \n";
            cin >> arr_n;
            system("cls");
            if (arr_n >= 10000)break;
            cout << "введите баллы каждого участника" << endl << "\n";
          
            static int* arrA = new int[arr_n];
            for (int i = 0; i < arr_n; i++) {
                cout << "учатсник " << i + 1 << " ";
                cin >> arrA[i];
                if (arrA[i] > 100) {
                    cout << "максимальное количество баллов - 100\nвведите другие баллы:\n\t ";
                    cin >> arrA[i];
                }

                cout << "\n";
            }
       
            for (int i = 0; i < arr_n; i++) {
                cout << "участник " << i + 1 << " баллы: " << arrA[i] << "\n";
            }
            cout << "---------------------------------------------\n";

            bubble_sort_obr(arrA, arr_n);
            //Вывод массива
            cout << "Отсортированный вариант: \n";
            for (int i = 0; i < arr_n; i++) {
             
                cout << "участник " << i + 1 << " баллы:" << arrA[i] << "\n";
            }
            cout << "---------------------------------------------\n";
            int l = 0;
            int i = 0;
            int sravn = 0;
            int kolvo = 0;
            while (l != 3) {
                kolvo++;
                if (arrA[i] != arrA[i + 1]) {
                    l++;
                }
                i++;
            }
            cout << "---------------------------------------------\n";
            cout << "Призовых мест: " << kolvo << endl;
            system("pause");
            break;
        }

        case '3': {
            system("cls");
            cout << "Конец\n";
            return 0;
            break;
        }

                //Невернай вариант выполнения 
        default: {
            cout << "_______________________________________________________\n";
            cout << "Вы ввели некорректный вариант выполнения\t!!!!!!!\n";
            cout << "программы,и были возвращены в меню\t\t!!!!!!!\n";
            cout << "_______________________________________________________\n\n\n";
            break;
        }
        }
    }
    return 0;
}


