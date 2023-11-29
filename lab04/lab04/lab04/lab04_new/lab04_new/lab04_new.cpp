#include <iostream>

using namespace std;

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
    system("color 02");
    setlocale(LC_ALL, "rus");
    int forar = 1;
    while (forar != 0) {
        char n;
        system("cls");
        //Меню
        cout << "1 - Задание 1\n";
        cout << "2 - Задание 2\n";
        cout << "3 - Выход\n";
        cout << "?: ";
        cin >> n;
        system("cls");

        //Варианты выполнения программы
        switch (n) {

            //Вариант 1 Игра 
        case '1': {

            int arr_n;
            cout << "Введите количество элементов в массиве: ";
            cin >> arr_n;
            system("cls");
            if (arr_n >= 10000)break;
            //Генерация и заполнение случайными числами одномерного динамического массива
            static int* arrA = new int[arr_n];
            for (int i = 0; i < arr_n; i++) {
                arrA[i] = rand() % 100;
            }
            cout << "\nКорзина: \n";
            //Вывод массива
            for (int i = 0; i < arr_n; i++) {
                cout << arrA[i] << " ";
            }

            bubble_sort(arrA, arr_n);
            //Вывод массива
            cout << "\nОтсортированная корзина: \n";
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
                    if (i != (arr_n - 1))
                        maxsum = maxsum + arrA[jfor];
                }
            }
            for (int i = arr_n - 1; i >= 0; i--) {
                if (i % 2 != 0) {
                    arrB[i] = arrA[jformin];
                    jformin--;
                }
                if (i == (arr_n - 2)) {
                    arrB[i] = arrA[0];
                }
            }


            cout << "\nЧек: \n";
            //Вывод массива
            for (int i = 0; i < arr_n; i++) {
                cout << arrB[i] << " ";
            }
            cout << "Максимальнаяя сумма чека = " << maxsum << endl;
            system("pause");
            break;
        }
        case '2': {
            system("cls");


            int arr_n;
            cout << "Введите количество элементов в массиве: \n";
            cin >> arr_n;
            system("cls");
            if (arr_n >= 10000)break;
            //Генерация и заполнение случайными числами одномерного динамического массива
            static int* arrA = new int[arr_n];
            for (int i = 0; i < arr_n; i++) {
                cout << " Ввод " << i + 1 << " участник: ";
                cin >> arrA[i];
                if (arrA[i] > 100) {
                    cout << "максимальное количество баллов - 100, введите другой балл" << endl;
                    cin >> arrA[i];
                    cout << endl;
                }
            }
            cout << "\nУчастники: \n";
            //Вывод массива
            for (int i = 0; i < arr_n; i++) {
                cout << arrA[i] << "\t";
            }
            cout << "\n";

            bubble_sort_obr(arrA, arr_n);
            //Вывод массива
            cout << "\nУчастники по убыванию: \n";
            for (int i = 0; i < arr_n; i++) {
                cout << arrA[i] << "\t";
            }
            cout << "\n";
            int l = 0;
            int i = 0;
            int k = 0;
            int sravn = 0;
            int kolvo = 0;
            while (l != 3) {
                kolvo++;
                if (arrA[i] != arrA[i + 1]) {
                    l++;
                }
                else
                    k++;
                i++;
            }
            if (k == (arr_n - 2)) {
                cout << "\nКоличество призёров = " << arr_n << endl;
            }
            else
                cout << "\nКоличество призёров = " << kolvo << endl;
            system("pause");
            break;
        }

        case '3': {
            system("cls");
            return 0;
            break;
        }

                //Невернай вариант выполнения 
        default: {
            cout << "Вы ввели некорректный вариант выполнения\n";
            cout << "программы,и были возвращены в меню";
            break;
        }
        }
    }
    return 0;
}




//#include <iostream>
//#include <stdlib.h>
//#include <string>
//
//using namespace std;
//
//int* bubble_sort(int* arr, int n) {
//
//    int temp = 0;
//
//    for (int i = 0; i < n - 1; i++) {
//        for (int j = i + 1; j < n; j++) {
//            if (arr[i] > arr[j]) {
//                temp = arr[i];
//                arr[i] = arr[j];
//                arr[j] = temp;
//            }
//        }
//    }
//
//    return arr;
//}
//
//string str;
//
//int main() {
//    setlocale(LC_ALL, "rus");
//    srand(time(NULL));
//
//    bool flag = true;
//    while (flag) {
//        system("cls");
//        int n, sum = 0, i, j, k;
//
//        while (true) {
//            flag = true;
//            system("cls");
//            cout << "Введите количество элементов в массиве\n";
//            cin >> str;
//            for (i = 0; i < size(str); i++)
//                if (!isdigit(str[i])) {
//                    system("cls");
//                    cout << "Неккоректное значение\n";
//                    system("pause");
//                    flag = false;
//                }
//            if (flag) {
//                break;
//            }
//        }
//        n = stoi(str);
//        if (n > 10000) break;
//        int* arr = new int[n];
//        for (int i = 0; i < n; i++) {
//            arr[i] = rand() % 100 + 1;
//        }
//        for (i = 0; i < n; i++) {
//            cout << arr[i] << " ";
//        }
//        cout << "\n\n";
//        bubble_sort(arr, n);
//        for (i = 0; i < n; i++) {
//            cout << arr[i] << " ";
//        } 
//        cout << "\n\n";
//        int* arrB = new int[n];
//        i = 0, j = n - 1, k = 0;
//        while(i <= j) {
//            if (i < j) {
//                arrB[k] = arr[j];
//                cout << arrB[k] << " ";
//                sum += arrB[k];
//                k++;
//                arrB[k] = arr[i];
//                cout << arrB[k] << " ";
//                k++, i++, j--;
//            }
//            else {
//                arrB[k] = arr[i];
//                cout << arr[i] << " ";
//                sum += arrB[k];
//                i++;
//            }
//        }
//
//        cout << "- это один из возможных вариантов вывода\n\n" <<sum << " - максимальная сумма на счёте чека\n";
//        system("pause");
//        system("cls");
//
//        while (true) {
//            flag = true;
//            system("cls");
//            cout << "Введите количество элементов в массиве\n";
//            cin >> str;
//            for (i = 0; i < size(str); i++)
//                if (!isdigit(str[i])) {
//                    system("cls");
//                    cout << "Неккоректное значение\n";
//                    system("pause");
//                    flag = false;
//                }
//            if (flag) {
//                break;
//            }
//        }
//        n = stoi(str);
//        if (n > 10000) break;
//
//        int* arrA = new int[n];
//        int counter = 0, number = 0;
//
//        for (int i = 0; i < n; i++) {
//            cin >> arrA[i];
//        }
//        for (i = 0; i < n; i++) {
//            cout << arrA[i] << " ";
//        }
//        cout << "\n\n";
//        bubble_sort(arrA, n);
//        for (i = 0; i < n; i++) {
//            cout << arrA[i] << " ";
//        }
//        cout << "\n\n";
//        
//        i = n - 1;
//
//        while (number != 3 && counter<n) {
//            counter++;
//            if (arrA[i] != arrA[i - 1]) {
//                number++;
//            }
//            i--;
//        }
//
//        cout << counter;
//        cout << "\n\nХотите продолжить?(1 - да, 2 - нет)\n";
//        cin >> n;
//        switch (n) {
//        case 1: break;
//        case 2: flag = false; break;
//        default: cout << "Некорректное значение" << endl; break;
//        }
//        delete[] arr;
//        delete[] arrA;
//        delete[] arrB;
//    }
//    return 0;
