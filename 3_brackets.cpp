#include <iostream>
#include <string>

using namespace std;

struct stack {
    char *bkt = new char;
    int cur = 0;

    void push(char x) {
        bkt[cur++] = x;
    }

    void pop() {
        cur--;
    }

    char back() {
        return bkt[cur - 1];
    }

    int size() {
        return cur;
    }
};

int main() {
    string brace;
    cin >> brace;
    stack x;
    if (brace[0] == '(' || brace[0] == '{' || brace[0] == '[')
        x.push(brace[0]);
    else {
        if (brace.empty()) cout << "YES";
        else cout << "NO";
        return 0;
    }
    for (int i = 1; i < brace.length(); i++) {
        if (brace[i] == '(' || brace[i] == '{' || brace[i] == '[') { //Любую открывающую скобку добавляем в стек
            x.push(brace[i]);
        } else if (abs(brace[i] - x.back()) < 3 && x.size() != 0) {
            x.pop();
        } else {
            cout << "NO";
            return 0;
        }
    }
    if (x.size() == 0) cout << "YES";
    else cout << "NO";
    return 0;
}