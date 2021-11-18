//
// Created by wang on 2021/11/17.
//
#include <bits/stdc++.h>

#define inf 0x3f3f3f3f
#define maxn 1000000

using namespace std;
typedef long long ll;
int n, m;
int arr[maxn];

int main() {
    cin >> n >> m;
    int tem, tt;
    while (n--) {
        cin >> tem;
        for (int i = 1; i <= tem; i++) {
            cin >> tt;
            if (!arr[tt]) {
                arr[tt] = 1;
            }
        }
    }
    bool bo = 0;
    for (int i = 1; i <= m; i++) {
        if (!arr[i]) {
            cout << "NO" << endl;
            bo = 1;
            break;
        }
    }
    if (!bo) {
        cout << "YES" << endl;
    }
    return 0;
}
