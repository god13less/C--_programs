//
// Created by wang on 2021/9/22.
//

#include <bits/stdc++.h>

using namespace std;
typedef long long LL;
const int N = 1e5 + 5;
int a[N], b[N];

inline int read() {
    int x = 0;
    char ch;
    for (ch = getchar(); !isdigit(ch); ch = getchar());
    for (; isdigit(ch); ch = getchar())x = (x << 1) + (x << 3) + (ch ^ 48);
    return x;
}

int main() {
    int n;
    n = read();
    for (int i = 0; i < n; i++)
        cin >> a[i];
    for (int i = 0; i < n; i++)
        cin >> b[i];
    sort(a, a + n);
    sort(b, b + n);
    LL ans1 = 0, ans2 = 0;
    int i = n - 1, j = n - 1;
    for (int k = 0; k < n; k++) {
        if (i >= 0 && a[i] > b[j]) ans1 += a[i--];
        else j--;
        if (j >= 0 && b[j] > a[i]) ans2 += b[j--];
        else i--;
    }
    cout << ans1 - ans2 << endl;
    return 0;
}