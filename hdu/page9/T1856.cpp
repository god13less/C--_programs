//
// Created by wang on 2021/7/7.
//

#include <bits\stdc++.h>

#define endl "\n"
#define maxn 10000050
using namespace std;
typedef int ll;
const double PI = acos(-1.0);
const double EI = exp(1.0);
const int inf = 0x3f3f3f3f;
ll n;
ll pre[maxn];
ll num[maxn];

void init() {
    for (int i = 1; i <= n; i++) {
        pre[i] = i;
        num[i] = 1;
    }
}

ll Find(ll x) {
    if (x == pre[x]) {
        return x;
    }
    return pre[x] = Find(pre[x]);
}

void Union(ll x, ll y) {
    ll fx = Find(x);
    ll fy = Find(y);
    if (fx == fy) {
        return;
    }
    pre[fx] = fy;
    num[fy] += num[fx];
}

int main() {
    std::ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    while (cin >> n) {
        init();
        ll a, b;
        for (int i = 0; i < n; i++) {
            cin >> a >> b;
            Union(a, b);
        }
        ll ma = 1;
        for (int i = 1; i <= n; i++) {
            ma = max(ma, num[pre[i]]);
        }
        cout << ma << endl;
    }

    return 0;
}