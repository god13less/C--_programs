//
// Created by wang on 2021/2/18.
//

#include <iostream>

using namespace std;
typedef long long ll;

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

int main() {
    ll a, b, c, k, T, Q;
    while (cin >> a >> b >> c >> k) {
        if (a == 0 && b == 0 && c == 0 && k == 0) {
            return 0;
        }
        ll B = (__int64) 1 << k;
        ll C = b - a;
        ll A = c;
        ll d = ex_gcd(A, B, T, Q);
        if ((C % d) != 0) {
            cout << "FOREVER" << endl;
        } else {
            ll ans = T * (C / d) ;
            ll temp = B / d ;
            ans = ( ans % temp + temp ) % temp ;
            cout << ans << endl;
        }
    }
    return 0;
}
