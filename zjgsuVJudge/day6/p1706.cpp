//
// Created by wang on 2021/2/18.
//

#include <iostream>

using namespace std;

int n;
int a[12], b[12];

void dfs(int k) {
    if (k == n + 1) {
        for (int i = 1; i <= n; i++) {
            cout << "    " << a[i];
        }
        cout << endl;
        return;
    }
    for (int i = 1; i <= n; i++) {
        if (!b[i]) {
            b[i] = 1;
            a[k] = i;
            dfs(k + 1);
            b[i] = 0;
        }
    }

}

int main() {
    cin >> n;
    for (int i = 0; i < 12; i++) {
        b[i] = 0;
    }
    dfs(1);
    return 0;
}
