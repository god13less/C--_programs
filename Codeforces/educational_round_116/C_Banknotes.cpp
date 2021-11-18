//
// Created by wang on 2021/10/31.
//
#include <bits/stdc++.h>
#define inf 0x3f3f3f3f
#define maxn 1000000

using namespace std;
typedef long long ll;
ll c[30], arr[12];
ll t, n, k;
int main() {
    c[0] = 1;
    for (int i = 1; i <= 32; i++) {
        c[i] = c[i - 1] * 10;
    }
    cin >> t;
    while (t--) {
        cin >> n >> k;
        k++;
        for (int i = 1; i <= n; i++) {
            cin >> arr[i];
        }
        ll ans = 0;
        for (int i = 1; i <= n; i++) {
            ans += min(k, c[arr[i + 1] - arr[i]] - 1) * c[arr[i]];
            k -= min(k, c[arr[i + 1] - arr[i]] - 1);
        }
        ans += k * c[arr[n]];
        cout<<ans<<endl;
    }
    return 0;
}
