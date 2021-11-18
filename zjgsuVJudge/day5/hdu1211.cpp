//
// Created by wang on 2021/1/31.
//

#include <iostream>
#include <cstdio>

using namespace std;
typedef long long ll;

ll n, p, q, e, l, d, fn, tem;

ll gcd(ll a, ll b) {
    if (b == 0) {
        return a;
    }
    return gcd(b, a % b);
}

ll quick_pow(ll a, ll b, ll c) {
    ll ans = 1, base = a;
    while (b != 0) {
        if (b & 1) {
            ans = ans * base % c;
        }
        base = base * base % c;
        b >>= 1;
    }
    return ans;
}

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

ll inv(ll a, ll mod) {
    ll x, y;
    ll GCD = ex_gcd(a, mod, x, y);
    return GCD ? (x % mod + mod) % mod : -1;
}

int main() {
    while (cin >> p >> q >> e >> l) {
        n = p * q;
        fn = (p - 1) * (q - 1);
        d = inv(e, fn);
        for (ll i = 0; i < l; i++) {
            cin >> tem;
            ll t = quick_pow(tem, d, n);
            printf("%c", t % 128);
        }
        cout << endl;
    }
    return 0;
}
