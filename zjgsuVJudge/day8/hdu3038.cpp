//
// Created by wang on 2021/2/18.
//

#include <iostream>

#define maxn 200050

using namespace std;

typedef long long ll;

ll pre[maxn], r[maxn];
ll n, m;

void init() {
    for (ll i = 1; i <= n + 1; i++) {
        pre[i] = i;
        r[i] = 0;
    }
}

ll find(ll x) {
    if (pre[x] == x) {
        return pre[x];
    }
    ll tem = find(pre[x]);
    r[x] += r[pre[x]];
    pre[x] = tem;
    return pre[x];
}

int main() {
    ll ai, bi, si, ans;
    while (cin >> n >> m) {
        init();
        ans = 0;
        for (ll i = 1; i <= m; i++) {
            cin >> ai >> bi >> si;
            bi++;
            int fx = find(ai);
            int fy = find(bi);
            if (fx != fy) {
                pre[fy] = fx;
                r[fy] = r[ai] + si - r[bi];
            } else {
                if (si != r[bi] - r[ai]) {
                    ans++;
                }
            }
        }
        cout << ans << endl;
    }
    return 0;
}
