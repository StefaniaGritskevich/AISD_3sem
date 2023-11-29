////#include <iostream>
////#include <string>
////#include <Windows.h>
////
////using namespace std;
////
////void main()
////{
////	SetConsoleCP(1251);
////	SetConsoleOutputCP(1251);
////
////	int N, M;
////	do
////	{
////		cout << "������� ��������������� �������: ";
////		cin >> N;
////		cin.clear();
////		cin.ignore(32767, '\n');
////	} while (N <= 0);
////	do
////	{
////		cout << "������� ���������� ���������: ";
////		cin >> M;
////		cin.clear();
////		cin.ignore(32767, '\n');
////	} while (M <= 0);
////
////
////	string* name = new string[M];
////	int* cost = new int[M];
////	int* ves = new int[M];
////
////	for (int i = 0; i < M; i++)
////	{
////		cout << "������� �������� " << i + 1 << " ��������: ";
////		cin >> name[i];
////		do
////		{
////			cout << "������� ��������� " << i + 1 << " ��������: ";
////			cin >> cost[i];
////			cin.clear();
////			cin.ignore(32767, '\n');
////		} while (cost[i] <= 0);
////		do
////		{
////			cout << "������� ��� " << i + 1 << " ��������: ";
////			cin >> ves[i];
////			cin.clear();
////			cin.ignore(32767, '\n');
////		} while (ves[i] <= 0);
////	}
////
////	int** A = new int* [M + 1]; // ������� ��� �������� ������������ ��������� ���������
////	for (int i = 0; i < M + 1; i++)
////	{
////		A[i] = new int[N + 1];
////	}
////
////	for (int i = 0; i < M + 1; i++)
////	{
////		for (int j = 0; j < N + 1; j++)
////		{
////			A[i][j] = 0;
////		}
////	}
////
////	for (int i = 1; i < M + 1; i++)
////	{
////		for (int j = 1; j < N + 1; j++)
////		{
////			if (j < ves[i - 1])
////			{
////				A[i][j] = A[i - 1][j]; // ���� ��� �������� ������ ����������� �������, �� ��������� �������� �� �����������
////			}
////			else
////			{
////				A[i][j] = max(A[i - 1][j], A[i - 1][j - ves[i - 1]] + cost[i - 1]);
////			}
////		}
////	}
////	cout << "������������ ��������� ���������, ���������� � ������: " << A[M][N] << "\n"
////		<< "��������, ���������� � ������: \n";
////	int i = M, j = N;
////	while (i > 0 && j > 0)
////	{
////		if (A[i][j] != A[i - 1][j])
////		{
////			cout << name[i - 1] << "\n";
////			j -= ves[i - 1];
////		}
////		i--;
////	}
////	cout << endl;
////	for (int i = 0; i < M + 1; i++)
////	{
////		delete[] A[i];
////	}
////	delete[] A;
////	delete[] name;
////	delete[] cost;
////	delete[] ves;
////}
//
//#include <iostream>
//#include <vector>
//#include <algorithm>
//#include <Windows.h>
//
//struct Item {
//    std::string name;
//    int weight;
//    int value;
//};
//
//bool compareItems(const Item& item1, const Item& item2) {
//    double ratio1 = static_cast<double>(item1.value) / item1.weight;
//    double ratio2 = static_cast<double>(item2.value) / item2.weight;
//    return ratio1 > ratio2;
//}
//
//int main() {
//    SetConsoleCP(1251);
//    SetConsoleOutputCP(1251);
//    int N;
//    std::cout << "������� ����������� ������� N: ";
//    std::cin >> N;
//
//    std::vector<Item> items;
//    int itemCount;
//    std::cout << "������� ���������� �������: ";
//    std::cin >> itemCount;
//
//    for (int i = 0; i < itemCount; ++i) {
//        Item item;
//        std::cout << "������� �������� ������: ";
//        std::cin >> item.name;
//        std::cout << "������� ��� ������: ";
//        std::cin >> item.weight;
//        std::cout << "������� ��������� ������: ";
//        std::cin >> item.value;
//        items.push_back(item);
//    }
//
//    std::sort(items.begin(), items.end(), compareItems);
//
//    int currentWeight = 0;
//    double totalValue = 0.0;
//    std::vector<std::string> selectedItems;
//
//    for (const Item& item : items) {
//        if (currentWeight + item.weight <= N) {
//            currentWeight += item.weight;
//            totalValue += item.value;
//            selectedItems.push_back(item.name);
//        }
//        else {
//            double remainingWeight = N - currentWeight;
//            totalValue += (remainingWeight / item.weight) * item.value;
//            break;
//        }
//    }
//
//    std::cout << "������������ ��������� ������� � �������: " << totalValue << std::endl;
//    std::cout << "�������� � �������: ";
//    for (const std::string& itemName : selectedItems) {
//        std::cout << itemName << " ";
//    }
//    std::cout << std::endl;
//
//    return 0;
//}
#include <iostream>
#include <string>

int main() {
    std::string str = "sdfgh";
    int number = std::stoi(str);
    std::cout << "��������������� �����: " << number << std::endl;
    return 0;
}
