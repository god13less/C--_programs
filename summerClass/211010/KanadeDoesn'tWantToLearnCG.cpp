//
// Created by wang on 2021/10/10.
//
#include <bits/stdc++.h>

#define inf 0x3f3f3f3f
#define maxn 1000000

using namespace std;
typedef long long ll;
ll t, x, x2, y, y2, y3, a, b, c;

ll f(ll x) {
    return a * (x * x) + b * x + c;
}

int main() {
    cin >> t;
    while (t--) {
        cin >> a >> b >> c;
        cin >> x >> x2 >> y2 >> y >> y3;
        if (f(x2) == y2) {
            cout << "NO" << endl;
        } else if (f(x) > y2 && f(2 * x2 - x) < y2 && f(x2) < y3 && f(x2) > y2) {
            cout << "Yes" << endl;
        } else if (f(x) > y2 && f(x2) < y) {
            cout << "Yes" << endl;
        } else {
            cout << "No" << endl;
        }
    }
    return 0;
}
