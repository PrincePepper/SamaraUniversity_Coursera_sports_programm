//
// Created by User on 29.07.2020.
//
#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> a;
vector<int> p;
vector<int> pa;
vector<bool> used;
int n;
int ans = INT_MAX;

void rec(int idx, int len) {
    if (len >= ans) {
        return;
    }
    if (idx == n) {
        ans = min(ans, len + a[p[idx - 1]][0]);
        cout << ans << "      ";
        for (int i : pa)
            cout << i << " ";
        cout << endl;
        return;
    }
    for (int i = 1; i <= n - 1; i++) {
        if (used[i])
            continue;
        p[idx] = i;
        used[i] = true;
        pa.push_back(i);
        rec(idx + 1, len + a[p[idx - 1]][i]);
        pa.pop_back();
        used[i] = false;
    }
}

int main() {
    cin >> n;
    int temp = 0;
    a = vector<vector<int>>(n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> temp;
            a[i].push_back(temp);
        }
    }
    used = vector<bool>(n, false);
    p = vector<int>(n, 0);
    rec(1, 0);
}
