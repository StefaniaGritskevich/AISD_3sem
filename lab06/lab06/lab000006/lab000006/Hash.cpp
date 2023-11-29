#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <ctime>

using namespace std;

int choose;
clock_t start;
clock_t end_time;
float n = rand() % 10 - 2;

template<typename T>
struct Hash {
    int flight_number;
    T destination;
    bool state;
};

template<typename T>
class NumTable {
private:
    int table_size; // ������ �������
    vector<vector<Hash<T>>> table; // ���-�������

    // ��������� ��������� ����� a � b ��� ������ �������������� �����������
    void generate_random_numbers(int& a, int& b) {
        
        a = rand() % table_size + 1;
        b = rand() % table_size - 1;
    }

    // ���������� ���-������� ������� �������������� �����������
    int universal_hash(int key, int a, int b) {
        int p = 10000019; // ������� �����
        return ((a * key + b) % p) % table_size;
    }

public:
    // �����������, ��������� ������ ���-������� ��������� �������
    NumTable(int size) {
        table_size = size;
        table.resize(size);
    }

    //������ ��� ������ � ��������
    void Add(int flight_number, T destination);
    void Search(int flight_number);
    void Print();
    void Delete(int flight_number);
};

// ���������� ����� ���������� �� ���������
template<typename T>
void NumTable<T>::Add(int flight_number, T destination) {
    int a, b;
    generate_random_numbers(a, b);
    int hash_value = universal_hash(flight_number, a, b); // ���������� ����� �������������� �����������

    for (const auto& entry : table[hash_value]) {
        if (entry.flight_number == flight_number) {
            cout << "������� � ����� ������ ��� ����������!" << endl;
            return;
        }
    }

    table[hash_value].push_back({ flight_number, destination, true });
}

//����� ���������� �� ������ �����
template<typename T>
void NumTable<T>::Search(int flight_number) {
    start = clock();
    int a, b;
    generate_random_numbers(a, b);
    int hash_value = universal_hash(flight_number, a, b); // ���������� ����� �������������� �����������

    int i = 0;

    while (i < table_size)
    {
        if (!table[hash_value].empty())
        {
            bool find = false;

            for (int j = 0; j < table[hash_value].size(); j++)
            {
                if (table[hash_value][j].flight_number == flight_number && !find)
                {
                    cout << "������ " << table[hash_value][j].flight_number << " - " << table[hash_value][j].destination << endl;
                    cout << "������ " << table[hash_value][j+1].flight_number << " - " << table[hash_value][j+1].destination << endl;

                    find = true;
                    end_time = clock();
                    cout << "����� ������:" << 1 / (end_time - start + n) << "�\n";
                    return;
                }
            }

            if (find == false)
            {
                hash_value = (hash_value + 1) % table_size;
            }
        }
        else {
            hash_value = (hash_value + 1) % table_size;
        }

        i++;
    }
}

template<typename T>
void NumTable<T>::Print() {
    for (int i = 0; i < table_size; i++) {
        if (table[i].empty()) {
            continue;
        }
        cout << "������ " << i << ": ";
        for (int j = 0; j < table[i].size(); j++) {
            if (table[i][j].state)
            {
                cout << "(" << table[i][j].flight_number << ", " << table[i][j].destination << ") ";
            }
            else {
                cout << "������� ������!";
            }
        }
        cout << endl;
    }
}

template<typename T>
void NumTable<T>::Delete(int flight_number)
{
    int a, b;
    int i = 0;

    generate_random_numbers(a, b);

    int hash_value = universal_hash(flight_number, a, b);

    while (i < table_size)
    {
        if (!table[hash_value].empty())
        {
            bool find = false;

            for (int j = 0; j < table[hash_value].size(); j++)
            {
                if (table[hash_value][j].flight_number == flight_number)
                {
                    table[hash_value][j].state = false;
                    cout << "������� ������� ������" << endl;
                    return;
                }
            }

            if (find == false)
            {
                hash_value = (hash_value + 1) % table_size;
            }
        }
        else {
            hash_value = (hash_value + 1) % table_size;
        }
        i++;
    }
}

void Menu()
{
    cout << "������� �������(1)" << endl;
    cout << "�������� �������(2)" << endl;
    cout << "����� �������(3)" << endl;
    cout << "������� �������(4)" << endl;

    cin >> choose;
}

int main() {
    setlocale(LC_ALL, "rus");

    int tableSize;
    cout << "������� ������ �������: "; cin >> tableSize;
    cout << endl << endl;
    NumTable<string> table(tableSize);
  long long  int number;
    string destriction;

    int searchNum;
    int delNum;

    Menu();

    while (choose != 5)
    {
        switch (choose)
        {
        case 1:
            cout << "����� ���-�������" << endl;
            table.Print();
            cout << endl << endl;

            Menu();
            break;
        case 2:
            cout << "���������� ��������" << endl;
            cout << "������� ����� ��������: ";
            cin >> number;
            while(number > 32767) {
                cout << "������� ������ �����, ������� ������ ��������:\n";
                cout << "������� ����� ��������: ";
                cin >> number;
            }
            cout << "������� ��� ��������: ";
            cin.ignore();
            getline(cin, destriction);


            table.Add(number, destriction);
            cout << endl;

            cout << "������� ������� ��������!" << endl << endl;

            Menu();
           
            break;
        case 3:
            cout << "����� ��������" << endl;
            cout << "������� ����� ��������: "; cin >> searchNum;
            table.Search(searchNum);
            cout << endl << endl;
            Menu();
            break;
        case 4:
            cout << "�������� ��������" << endl;
            cout << "������� ����� ��������: "; cin >> delNum;
            table.Delete(delNum);
            cout << endl << endl;
            Menu();
            break;
        }
    }

    return 0;
}