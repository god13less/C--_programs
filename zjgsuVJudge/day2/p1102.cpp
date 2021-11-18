//
// Created by wang on 2021/1/29.
//

//A-B数对

#include <iostream>
#include <map>

using namespace std;
typedef long long ll;

int main() {
    ll n, c, ans = 0;
    map<ll, ll> m;//num,times
    ll a[200050];
    cin >> n >> c;
    for (ll i = 0; i < n; i++) {
        cin >> a[i];
        m[a[i]]++;
        a[i] -= c;
    }
    for (ll i = 0; i < n; i++) {
        ans += m[a[i]];
    }
    cout << ans << endl;
    return 0;
}
