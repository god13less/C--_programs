#include <bits\stdc++.h>

#define endl "\n"
using namespace std;
typedef long long ll;
const ll mod = 200907;

ll quick_pow(ll a, ll b) {
    ll res = 1, ans = a;
    while (b > 0) {
        if (b & 1)
            res = (res * ans) % mod;
        ans = (ans * ans) % mod;
        b /= 2;
    }
    return res % mod;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t--) {
        ll s1, s2, s3, q;
        ll k;
        ll sum;
        cin >> s1 >> s2 >> s3 >> k;
        if (s2 - s1 == s3 - s2) {
            q = (s2 - s1) % mod;
            sum = (s1 + (q * ((k - 1) % mod)) % mod) % mod;
        } else {
            q = (s2 / s1) % mod;
            sum = ((s1 % mod) * (quick_pow(q, k - 1))) % mod;
        }
        cout << sum << endl;
    }
    return 0;
}