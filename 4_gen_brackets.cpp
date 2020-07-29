//
// Created by Semen Sereda on 29.07.2020.
//

#include <iostream>
#include <string>
#include <vector>

using namespace std;

string next(string s) {
    int n = (int) s.length();
    string ans = "-1";
    for (int i = n - 1, depth = 0; i >= 0; --i) {
        if (s[i] == '(')
            --depth;
        else
            ++depth;
        if (s[i] == '(' && depth > 0) {
            --depth;
            int open = (n - i - 1 - depth) / 2;
            int close = n - i - 1 - open;
            ans = s.substr(0, i) + ')' + string(open, '(') + string(close, ')');
            break;
        }
    }
    return ans;
}

void order(int n) {
    string s = "";
    for (int i = 1; i <= n; i++) {
        s += '(';
    }
    for (int i = 1; i <= n; i++) {
        s += ')';
    }
    cout << s << endl;
    while (next(s) != "-1") {
        s = next(s);
        cout << s << endl;
    }
}

vector<char> s;
int n;
char a_1[2]={'(','['};
char a_2[2]={')',']'};
void rec(int idx=0, int bal=0,int k=0) {
    if (idx == 2 * n) {
        if (bal == 0) {
            for (int i = 0; i < idx; i++)
                cout << s[i];
            cout << endl;
        }
        return;
    }
    s[idx] = a_1[k];
    rec(idx + 1, bal + 1,k);
    if (bal == 0){
        k=k%1;
    }
    s[idx] = a_2[k];
    rec(idx + 1, bal - 1,k);
}

int main() {
    cin >> n;
    s = vector<char>(n*2);
    rec();
    /// ИЛИ
    cout << endl;
    //order(n);
}