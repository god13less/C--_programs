//
// Created by wang on 2021/8/12.
//

#include <bits\stdc++.h>

#define endl "\n"
using namespace std;
typedef long long ll;
const double PI = acos(-1.0);
const double EI = exp(1.0);
const int maxn = 5050;

inline ll rd() {
    ll x = 0;
    char c = getchar();
    bool f = 0;
    while (!isdigit(c)) {
        if (c == '-')f = 1;
        c = getchar();
    }
    while (isdigit(c)) {
        x = (x << 1) + (x << 3) + (c ^ 48);
        c = getchar();
    }
    return f ? -x : x;
}

int n;
struct node {
    ll x, y;
} p[maxn];
int vis[maxn];

ll quick_pow(ll a, ll b) {
    ll ans = 1, base = a;
    while (b != 0) {
        if (b & 1) {
            ans = ans * base;
        }
        base = base * base;
        b >>= 1;
    }
    return ans;
}

ll dist(node a, node b) {
    return quick_pow(a.x - b.x, 2) + quick_pow(a.y - b.y, 2);
}

ll pre[maxn];

void init() {
    for (int i = 0; i <= maxn; i++) {
        pre[i] = i;
    }
}

ll Find(ll x) {
    if (x != pre[x]) {
        pre[x] = Find(pre[x]);
    }
    return pre[x];
}

void Union(ll x, ll y) {
    ll fx = Find(x);
    ll fy = Find(y);
    if (fx != fy) {
        pre[fy] = fx;
    }
}

int main() {
    int t, index;
    t = rd();
    while (t--) {
        memset(vis, 0, sizeof vis);
        n = rd();
        for (int i = 1; i <= n; i++) {
            p[i].x = rd();
            p[i].y = rd();
        }
        for (int i = 1; i <= n - 1; i++) {
            ll minn = 9223372036854775807;
            int index;
            for (int j = i + 1; j <= n; j++) {
                ll tem = dist(p[i], p[j]);
                if (tem < minn) {
                    minn = tem;
                    index=j;
                }
            }
            Union(i, index);
        }

    }

    return 0;
}