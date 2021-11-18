//
// Created by wang on 2021/10/13.
//
#include <bits/stdc++.h>

#define inf 0x3f3f3f3f
#define maxn 1000000

using namespace std;
typedef long long ll;

inline int read() {
    int x = 0;
    char ch;
    for (ch = getchar(); !isdigit(ch); ch = getchar());
    for (; isdigit(ch); ch = getchar())x = (x << 1) + (x << 3) + (ch ^ 48);
    return x;
}

int main() {
    int t = read();
    bool flag;
    while (t--) {
        flag = 0;
        int n = read();
        if (n % 7 == 0) {
            flag=1;
        } else if (n % 3 == 0) {
            flag=1;
        }
        if (!flag) {
            for (int i = 1; i <= 15; i++) {
                for (int j = 1; j <= 35; j++) {
                    if (n % (i * 7 + j * 3) == 0) {
                        flag=1;
                        break;
                    }
                }
                if (flag) {
                    break;
                }
            }
        }
        if (flag) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }

    return 0;
}
