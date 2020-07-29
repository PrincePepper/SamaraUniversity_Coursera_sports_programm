//
// Created by Semen Sereda on 28.07.2020.
//
///Перебор всех возможных комбинаций чисел от 1 до M размером N
///Используется рекурсивный способ функции rec()
///асимптотика O(N*M)
#include <iostream>
#include <vector>

using namespace std;




int n, m;
vector<int> a;

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
    for (int i = 1; i <= m; i++) {
        a[idx] = i;
        rec(idx + 1);
    }
}

int main() {
    cin >> n >> m;
    a = vector<int>(n);
    rec(0);
}