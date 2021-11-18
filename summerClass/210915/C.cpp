//
// Created by wang on 2021/9/15.
//
#include <bits/stdc++.h>

#define inf 0x3f3f3f3f

#define maxn 200010
using namespace std;
typedef long long ll;

int my_mod(int a, int mod) {
    if (a >= 0) {
        return a % mod;
    } else {
        int tem = a % mod;
        if (tem == 0) {
            return tem;
        }
        int y = fabs(tem / mod) + 1;
        return y * mod + tem;
    }
}

int n;
int arr[maxn];
int flag[maxn];
int dsd;

int main() {
    int t;
    cin >> t;
    while (t--) {
        dsd = 0;
        memset(flag, 0, sizeof flag);
        cin >> n;
        for (int i = 1; i <= n; i++) {
            cin >> arr[i];
        }
        for (int i = 1; i <= n; i++) {
            int tem = my_mod((i + arr[i]), n);
            if (!flag[tem]) {
                flag[tem]++;
            } else {
                dsd = 1;
                break;
            }
        }
        if (dsd) {
            cout << "NO" << endl;
        } else {
            cout << "YES" << endl;
        }

    }
    return 0;
}
