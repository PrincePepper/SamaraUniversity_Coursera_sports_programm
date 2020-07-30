//
// Created by Semen Sereda on 30.07.2020.
//
#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>

using namespace std;
typedef pair<long long int, long long int> valueAndindex;



int main() {
    ifstream fin;
    ofstream fout;
    fin.open("input.txt");
    long long int n, temp1, temp2;
    fin >> n;
    vector<valueAndindex> rec;
    long long int cnt = 1;
    long long int last = 0;
    for (long long int i = 0; i < n; i++) {
        fin >> temp1 >>temp2 ;
        rec.emplace_back(temp2, temp1);
    }
    sort(rec.begin(), rec.end());
    for (long long int i = 1; i < n; i++)
        if (rec[i].second >= rec[last].first) {
            cnt++;
            last = i;
        }
    cout << cnt;
}


