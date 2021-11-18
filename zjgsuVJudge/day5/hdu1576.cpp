//
// Created by wang on 2021/1/31.
//

#include <iostream>

using namespace std;
typedef long long ll;

ll t, n, b;

ll ex_gcd(ll a, ll b, ll &x, ll &y) {
    ll GCD, t;
    if (!b) {
        x = 1;
        y = 0;
        return a;
    }
    GCD = ex_gcd(b, a % b, x, y);
    t = x;
    x = y;
    y = t - (a / b) * y;
    return GCD;
}

ll inv(int a, int mod) {
    ll x, y;
    ll GCD = ex_gcd(a, mod, x, y);
    return GCD ? (x % mod + mod) % mod : -1;
}

int main() {
    while (cin >> t) {
        for (int i = 0; i < t; i++) {
            cin >> n >> b;
            ll ans;
            ans = n * inv(b, 9973) % 9973;
            cout << ans << endl;
        }
    }
    return 0;
}