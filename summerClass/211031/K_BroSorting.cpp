//
// Created by wang on 2021/10/31.
//

#include <iostream>
#include <cstring>

#define inf 0x3f3f3f3f
#define maxn 1000060

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
int vis[maxn];

int main() {
    t = read();
    for (int k = 1; k <= t; k++) {
        n = read();
        int ans = 0;
        int mn=inf;
        memset(vis, 0, sizeof vis);
        for (int i = 1; i <= n; i++) {
            arr[i] = read();
        }
        for (int i = n; i >=1; i--) {
            if (arr[i] < mn) {
                mn = arr[i];
            } else if (arr[i] > mn) {
                ans++;
            }
        }
        cout << "Case #" << k << ": " << ans << endl;

    }

    return 0;
}