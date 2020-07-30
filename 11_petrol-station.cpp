//
// Created by Semen Sereda on 30.07.2020.
//
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    long long int n, m, max;
    cin >> n >> m >> max;
    vector<long long int> a(n);
    for (long long int i = 0; i < n; i++) {
        cin >> a[i];
    }
    long long int cnt = 1;
    long long int last = 0;
    for (long long int i = 0; i < n; i++) {
        if (max+last<=a[i]) {
            cnt++;
            last = a[i-1];
        }
        cout<<i<<endl;
    }
    cout<<cnt;
}



