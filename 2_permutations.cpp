//
// Created by Semen Sereda on 28.07.2020.
//
///Это генерация перестановок или по другому:
///выборка без повторений элементов
///асимптотика O(N!)

#include <vector>
#include <iostream>

using namespace std;

int n;
vector<int> a;
vector<bool> used;

void rec(int idx) {
    if (idx == n) {
        for (int i = 0; i < n; i++) {
            if (i)
                cout << " ";
            cout << a[i];
        }
        cout << endl;
        return;
    }
    for (int i = 1; i <= n; i++) {
        if (used[i])
            continue;
        used[i] = true;
        a[idx] = i;
        rec(idx + 1);
        used[i] = false;
    }
}

int main() {
    cin >> n;
    a = vector<int>(n);
    used = vector<bool>(n);
    rec(0);
}