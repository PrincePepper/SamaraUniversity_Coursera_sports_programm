//
// Created by Semen Sereda on 29.07.2020.
//

///Это генерация разбиения числа на слагаемые

#include <iostream>

using namespace std;

int a[100];
int n;

void rec(int idx = 0, int sum = 0, int last = 1) {
    if (sum == n) {
        for (int i = 0; i < idx; i++) {
            if (i)
                cout << '+';
            cout << a[i];
        }
        cout << endl;
        return;
    }
    for (int i = last; i <= n - sum; i++) {
        a[idx] = i;
        rec(idx + 1, sum + i, i);
    }
}

int main() {
    cin >> n;
    rec();
}