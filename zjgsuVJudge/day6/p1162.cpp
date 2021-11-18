//
// Created by wang on 2021/2/16.
//

#include <iostream>

#define maxn 33
using namespace std;
typedef int ll;

int n;
int a[maxn][maxn];
const int hx[4] = {0, 1, 0, -1}, ly[4] = {1, 0, -1, 0};

void dfs() {
    for (int k = 0; k < 100; k++) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                if (a[i][j] != 1) {
                    if (a[i][j - 1] == 0 || a[i - 1][j] == 0 || a[i + 1][j] == 0 || a[i][j + 1] == 0) {
                        a[i][j] = 0;
                    }
                }
            }
        }
    }
}

int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> a[i][j];
            if (a[i][j] == 0) {
                a[i][j] = 2;
            }
        }
    }
    dfs();
    for (int i = 1; i <= n ; i++) {
        for (int j = 1; j <= n ; j++) {
            cout << a[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
