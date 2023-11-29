#include <iostream>
#include <stack>
#define strl 1000

using namespace std;

bool check(char a, char b) {
    char m[] = { '[',']', '{', '}', '(', ')' };
    for (int i = 0; i < 5; i += 2) {
        if (m[i] == a && m[i + 1] == b)
            return true;
    }
    return false;
}


int main()
{
    system("color 02");
    setlocale(LC_ALL, "rus");
    cout << "¬¬ъведите символьную строку котора€ может содержать цифры, буквы, знаки математических операций (+, -, *, /) и три вида скобок: (), [] и {}" << endl;
    stack<char> q;
    char s[strl];
    cin.getline(s, strl);
    char scob[strl];
    int scobS = 0;
    for (int i = 0; i < strlen(s); i++) {
        if (s[i] == '[' || s[i] == ']' || s[i] == '(' || s[i] == ')' || s[i] == '{' || s[i] == '}')
            scob[scobS++] = s[i];
    }
    scob[scobS] = '\0';
    cout << scob << endl;
    for (int i = 0; i < strlen(scob); i++)
    {
        if (q.empty()) {
            q.push(scob[i]);
        }
        else
        {
            if (check(q.top(), scob[i])) {
                q.pop();
            }
            else
                q.push(scob[i]);
        }
    }
    if (q.empty())
        cout << "вернo" << endl;
    else
    {
        cout << "невернo" << endl;
    }
}