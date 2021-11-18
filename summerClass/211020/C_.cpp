//
// Created by wang on 2021/10/21.
//

#include <bits/stdc++.h>

#define inf 0x3f3f3f3f
#define maxn 100009

using namespace std;
typedef long long ll;

int gcd(int a, int b) {
    if (b == 0) {
        return a;
    }
    return gcd(b, a % b);
}

int n;
int a[maxn];

int main() {
    cin >> n;
    cin >> a[1];
    int bo = 0;
    int tem = a[1];
    for (int i = 2; i <= n; i++) {
        cin >> a[i];
        tem = gcd(a[i], tem);
        if (tem < 2) {
            bo = 1;
        }
    }
    a[n + 1] = 0;
    if (!bo) {
        cout << "YES" << endl;
        cout << 0 << endl;
        return 0;
    }
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        if (a[i] % 2 == 1) {
            if (a[i + 1] % 2 == 1) {
                ans++;
            } else {
                ans += 2;
            }
            a[i] = a[i + 1] = 0;
        }
    }
    cout << "YES" << endl;
    cout << ans << endl;

    return 0;
}