//
// Created by Semen Sereda on 30.07.2020.
//

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void change(int n, vector<int> a, int sum) {
    int cnt = 0;
    for (int i = 0; i < n; i++) {
        int temp = sum / a[i];
        cnt += temp;
        for (int j = 0; j < temp; j++) {
            cout << a[i]<< '+';
        }

        sum %= a[i];
    }
    cout << endl << cnt;
}

int main() {
    int n, m, temp;
    cin >> n >> m;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> temp;
        a[i] = temp;
    }
    sort(a.begin(),a.end(),[](int a, int b){
        return a > b;
    });
    change(n, a, m);
}

