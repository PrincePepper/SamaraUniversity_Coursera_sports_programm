///Это генерация перестановок или по другому:
///выборка без повторений элементов
///асимптотика O(N!)
#include <fstream>
#include <vector>

using namespace std;

ifstream cin("input.txt");
ofstream cout("output.txt");

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