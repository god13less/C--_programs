//
// Created by wang on 2021/11/7.
//
#include <bits/stdc++.h>

#define inf 0x3f3f3f3f
#define maxn 1000000

using namespace std;
typedef long long ll;
ll t;
ll arr[1000];

void solve() {
    ll a, b;
    cin >> a >> b;
    a--;
    ll ans = 0, now = 1;
    while (a > 0 && now < b) {
        a -= now;
        ans++;
        now *= 2;
    }
    if (a > 0) ans += (a / b + (a % b > 0));
    cout << ans << endl;
}

int main() {
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
