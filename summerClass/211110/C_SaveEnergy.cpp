#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const ll mod = 1e9 + 7;

void solve() {
    ll k, d, t;
    cin >> k >> d >> t;
    if (k % d == 0) {
        double q = t;
        cout << fixed << setprecision(9) << q << endl;
    } else {
        if (k > d) {
            d = (k / d + 1) * d;
        }
        double tol = 0;
        ll q = 2 * k + d - k;
        tol += 1ll * (2 * t / q) * d;
        ll sum1 = (2 * t) % q;
        if (sum1 <= 2 * k) {
            tol += double(sum1 / 2.0);
        } else {
            tol += k;
            sum1 -= 2 * k;
            tol += sum1;
        }
        cout << fixed << setprecision(9) << tol << endl;
    }
}

int main() {
    solve();
    return 0;
}