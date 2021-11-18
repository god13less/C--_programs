//
// Created by wang on 2021/10/24.
//

#include <bits/stdc++.h>

#define inf 0x3f3f3f3f
#define maxn 400000

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
char c;
string str;

void save() {
    int ans;
    for (int i = 1; i <= n; i++) {
        ans = i;
        for (int j = i; j <= n; j += i) {
            if (str[j - 1] != c) {
                ans = 0;
            }
        }
        if (ans) {
            break;
        }
    }
    if (ans == 1) {
        cout << 0 << endl;
    } else if (ans > 1) {
        cout << 1 << endl << ans << endl;
    } else {
        cout << 2 << endl << n - 1 << " " << n << endl;
    }
}

int main() {
    cin >> t;
    while (t--) {
        cin >> n >> c >> str;
        save();
    }

    return 0;
}