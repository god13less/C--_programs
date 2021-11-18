//
// Created by wang on 2021/7/9.
//

#include <bits\stdc++.h>

#define endl "\n"
using namespace std;
typedef long long ll;
const double PI = acos(-1.0);
const double EI = exp(1.0);
const int inf = 0x3f3f3f3f;


ll multiply(ll n, ll m, ll mod) {
    ll sum = 0;
    while (m) {
        if (m & 1) {
            sum += n;
            sum %= mod;
        }
        m >>= 1;
        n *= 2;
        n %= mod;
    }
    return sum;
}


int main() {
    std::ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    ll n, ans;
    ll q, p;
    cin >> n;
    while (n--) {
        cin >> q >> p;
        ans = multiply(q-1,q-2,2*p);
        cout << ans / 2 << endl;
    }

    return 0;
}
