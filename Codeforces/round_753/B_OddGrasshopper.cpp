//
// Created by wang on 2021/11/12.
//
#include <bits/stdc++.h>

#define inf 0x3f3f3f3f
#define maxn 1000000

using namespace std;
typedef long long ll;
int t;
ll x0, n;

void save() {
    ll tem = n % 4;
    ll a = n / 4;
    if (x0 % 2 == 0) {
        if (tem == 0) {
            cout << x0 << endl;
        } else if (tem == 1) {
            cout << x0 - 1 - 4 * a << endl;
        } else if (tem == 2) {
            cout << 1 + x0 << endl;
        } else {
            cout << x0 + 4 + 4 * a << endl;
        }
    } else {
        x0--;
        if (tem == 0) {
            cout << 1 + x0 << endl;
        } else if (tem == 1) {
            cout << x0 + 2 + a * 4 << endl;
        } else if (tem == 2) {
            cout << x0 << endl;
        } else {
            cout << x0 - 3 - 4 * a << endl;
        }
    }
}

int main() {
    cin >> t;
    while (t--) {
        cin >> x0 >> n;
        save();
    }
    return 0;
}
