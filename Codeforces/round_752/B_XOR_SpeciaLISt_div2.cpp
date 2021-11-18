//
// Created by wang on 2021/11/11.
//
#include <bits/stdc++.h>

#define inf 0x3f3f3f3f
#define maxn 9000000

using namespace std;
typedef long long ll;

inline int read() {
    int x = 0;
    char ch;
    for (ch = getchar(); !isdigit(ch); ch = getchar());
    for (; isdigit(ch); ch = getchar())x = (x << 1) + (x << 3) + (ch ^ 48);
    return x;
}

int t, n;
int arr[maxn];

int main() {
    cin >> t;
    while (t--) {
        cin >> n;
        for (int i = 1; i <= n; i++) {
            cin >> arr[i];
        }
        if (n % 2 == 0) {
            cout << "YES" << endl;
            continue;
        } else {
            bool bo = false;
            for (int i = 1; i <= n - 1; i++) {
                if (arr[i] >= arr[i + 1]) {
                    bo = true;
                    break;
                }
            }
            if (bo) {
                cout << "YES" << endl;
            } else {
                cout << "NO" << endl;
            }
        }
    }
    return 0;
}
