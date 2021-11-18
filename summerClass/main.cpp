#include <bits/stdc++.h>

#define endl "\n"
#define INF 0x3f3f3f3f3f3f3f3f
#define IO ios::sync_with_stdio(false);cin.tie();cout.tie(0)
using namespace std;
typedef long long ll;
const ll mod = 1e9 + 7;
const double PI = acos(-1.0);
const double EI = exp(1.0);
const int N = 1e8 + 10;
const int maxn = 1e9 + 1;
const double eps = 1e-8;

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
    std::ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    //int t; cin >> t; while (t--)
    solve();
    return 0;
}