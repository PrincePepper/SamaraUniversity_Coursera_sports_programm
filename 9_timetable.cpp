//
// Created by Semen Sereda on 30.07.2020.
//
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
struct Order {
    int dedline, count;
};

inline bool operator<(const Order &O1, const Order &O2) {
    return (O1.count > O2.count);
}

int main() {
    int n;
    cin >> n;
    vector<Order> order;
    Order temp{0,0};
    for (int i = 0; i < n; i++) {
        cin >> temp.dedline>>temp.count;
        order.push_back(temp);
    }
    sort(order.begin(),order.end());
    vector<bool> used(n, false);
    long long sum = 0;
    for (int i = 0; i < n; i++) {
        int k = order[i].dedline;
        while (k >= 1 && used[k])
            k--;
        if (k == 0)
            continue;
        used[k] = true;
        sum += order[i].count;
    }
    cout << sum;
}

