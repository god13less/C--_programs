//
// Created by wang on 2021/8/12.
//

#include <bits\stdc++.h>

#define endl "\n"
using namespace std;
typedef long long ll;
const int inf = 0x3f3f3f3f;
const int maxn = 100050;
const int mod = 998244353;

struct node {
    int l, r;
    ll w;
} tree[maxn << 2];

ll quick_pow(ll a, ll b, ll c) {
    ll ans = 1, base = a;
    while (b != 0) {
        if (b & 1) {
            ans = ans * base % c;
        }
        base = base * base % c;
        b >>= 1;
    }
    return ans;
}

void build(int rt, int l, int r) {
    tree[rt].l = l;
    tree[rt].r = r;
    if (tree[rt].l == tree[rt].r) {
        scanf("%lld", &tree[rt].w);
        return;
    }
    int mid = (l + r) >> 1;
    build(rt << 1, l, mid);
    build(rt << 1 | 1, mid + 1, r);
    tree[rt].w = tree[rt << 1].w + tree[rt << 1 | 1].w;
}

ll K(ll a) {
    return ll(log(a) / log(2));
}

void update(int rt, int l, int r, int v) {
    if (tree[rt].w == 0) {
        return;
    }
    if (tree[rt].r == tree[rt].l && tree[rt].r <= r && tree[rt].r >= l) {
        if (v == 2) {
            tree[rt].w -= tree[rt].w & (-tree[rt].w);
            if (tree[rt].w < 0) {
                tree[rt].w = 0;
            }
        } else if (v == 3) {
            tree[rt].w += quick_pow(2, K(tree[rt].w), mod);
        }
        return;
    }
    int mid = (tree[rt].l + tree[rt].r) >> 1;
    if (r <= mid) {
        update(rt << 1, l, r, v);
    } else if (l > mid) {
        update(rt << 1 | 1, l, r, v);
    } else {
        update(rt << 1, l, mid, v);
        update(rt << 1 | 1, mid + 1, r, v);
    }
    tree[rt].w = (tree[rt << 1].w + tree[rt << 1 | 1].w) % mod;
}

int query(int rt, int l, int r) {
    if (l <= tree[rt].l && r >= tree[rt].r) {
        return tree[rt].w;
    }
    int ans = 0;
    int mid = (tree[rt].l + tree[rt].r) >> 1;
    if (l <= mid) {
        ans = (ans + query(rt << 1, l, r)) % mod;
    }
    if (r > mid) {
        ans = (ans + query(rt << 1 | 1, l, r)) % mod;
    }
    return ans;
}

int main() {
    int t, n, m, k, l, r;
    scanf("%d", &t);
    while (t--) {
        scanf("%d", &n);
        build(1, 1, n);
        scanf("%d", &m);
        for (int i = 1; i <= m; i++) {
            scanf("%d%d%d", &k, &l, &r);
            if (k == 1) {
                printf("%lld\n", query(1, l, r));
            } else {
                update(1, l, r, k);
            }
        }
    }

    return 0;
}
