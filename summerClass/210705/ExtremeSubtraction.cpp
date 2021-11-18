//
// Created by wang on 2021/7/5.
// Codeforces 681 div2

#include <iostream>

#define inf 0x3f3f3f3f

using namespace std;
typedef long long ll;
ll t, n;
ll a[30050], b[30050];


int main() {
    cin >> t;
    for (int i = 0; i < t; i++) {
        cin >> n;
        for (int j = 1; j <= n; j++) {

            cin >> a[j];
            b[j] = a[j] - a[j - 1];
        }
        ll sum = 0;
        for (int j = 1; j <= n; j++) {
            if (b[j] < 0) {
                sum += b[j];
            }
        }
        if (a[1] + sum >= 0) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }

    return 0;
}
