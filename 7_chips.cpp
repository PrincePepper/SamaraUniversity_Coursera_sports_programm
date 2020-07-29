//
// Created by Semen Sereda on 29.07.2020.
//

///Это генерация разбиения числа на слагаемые

#include <iostream>
#include <vector>

using namespace std;

vector<char> s;
vector<bool> used;
int n, m;

void rec(int idx = 1, int len = 1) {
    if (idx == m + 1) {
        for (int i = 1; i <= n; i++) {
            cout << s[i];
        }
        cout << endl;
        return;
    }
    for (int i = len; i <= n; i++) {
        if (!used[i] && used[i - 1] == false) {
            used[i] = true;
            s[i] = '*';
            rec(idx + 1, i);
            used[i] = false;
            s[i] = '.';
        }
    }
}

int main() {
    cin >> n >> m;
    s = vector<char>(n + 1, '.');
    used = vector<bool>(n + 1);
    rec();
}
