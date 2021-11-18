//
// Created by wang on 2021/7/22.
//

#include <bits\stdc++.h>
#define mod 1000000007
#define endl "\n"
using namespace std;
typedef long long ll;
const double PI = acos(-1.0);
const double EI = exp(1.0);
const int inf = 0x3f3f3f3f;
ll n, q, b;
struct node {
    ll a, b;
};
struct tree {
    ll l, r;
    ll sum;
    node no;
} tree[200050];

void build(ll rt, ll l, ll r) {
    tree[rt].l = l;
    tree[rt].r = r;
    if (tree[rt].l == tree[rt].r) {
        cin >> tree[rt].no.a >> tree[rt].no.b;
        tree[rt].sum = tree[rt].no.a * tree[rt].no.b;
        return;
    }
    ll mid = (l + r) >> 1;
    build(rt << 1, l, mid);
    build(rt << 1 | 1, mid + 1, r);
    tree[rt].sum = tree[rt << 1].sum + tree[rt << 1 | 1].sum;
}

void update_1(ll rt, ll num, ll l, ll r, ll x) {
    if (l >= tree[rt].r || r <= tree[rt].l) {
        return;
    }
    if (tree[rt].l == tree[rt].r) {
        if (num) {
            tree[rt].no.b += x;
        } else {
            tree[rt].no.a += x;
        }
        tree[rt].sum = (tree[rt].no.a * tree[rt].no.b)%mod;
        return;
    }
    ll mid = (tree[rt].l + tree[rt].r) >> 1;
    if (r <= mid) {
        update_1(rt << 1, num, l, r, x);
    } else if (l >= mid) {
        update_1(rt << 1 | 1, num, l, r, x);
    } else {
        update_1(rt << 1, num, l, mid, x);
        update_1(rt << 1 | 1, num, mid + 1, r, x);
    }
    tree[rt].sum = (tree[rt << 1].sum + tree[rt << 1 | 1].sum)%mod;
}

void update_2(ll rt, ll l, ll r) {
    if (l >= tree[rt].r || r <= tree[rt].l) {
        return;
    }
    if (tree[rt].l == tree[rt].r) {
        ll an = tree[rt].no.a;
        ll bn = tree[rt].no.a;
        tree[rt].no.a = 3 * an + 2 * bn;
        tree[rt].no.b = 3 * an - 2 * bn;
        tree[rt].sum = (tree[rt].no.a * tree[rt].no.b)%mod;
        return;
    }
    ll mid = (tree[rt].l + tree[rt].r) >> 1;
    if (r <= mid) {
        update_2(rt << 1, l, r);
    } else if (l >= mid) {
        update_2(rt << 1 | 1, l, r);
    } else {
        update_2(rt << 1, l, mid);
        update_2(rt << 1 | 1, mid + 1, r);
    }
    tree[rt].sum = (tree[rt << 1].sum + tree[rt << 1 | 1].sum)%mod;
}

void update_3(ll rt, ll l, ll r) {
    if (l >= tree[rt].r || r <= tree[rt].l) {
        return;
    }
    if (tree[rt].l == tree[rt].r) {
        ll an = tree[rt].no.a;
        tree[rt].no.a = tree[rt].no.b;
        tree[rt].no.b = an;
        tree[rt].sum = (tree[rt].no.a * tree[rt].no.b)%mod;
        return;
    }
    ll mid = (tree[rt].l + tree[rt].r) >> 1;
    if (r <= mid) {
        update_3(rt << 1, l, r);
    } else if (l >= mid) {
        update_3(rt << 1 | 1, l, r);
    } else {
        update_3(rt << 1, l, mid);
        update_3(rt << 1 | 1, mid + 1, r);
    }
    tree[rt].sum = (tree[rt << 1].sum + tree[rt << 1 | 1].sum)%mod;
}

ll query(ll rt, ll l, ll r) {
    if (l <= tree[rt].l && r >= tree[rt].r) {
        return tree[rt].sum;
    }
    ll mid = (tree[rt].l + tree[rt].r) >> 1;
    ll ans = 0;
    if (l <= mid) {
        ans = (ans + query(rt << 1, l, r)) % mod;
    }
    if (r > mid) {
        ans = (ans + query(rt << 1 | 1, l, r)) % mod;
    }
    return ans;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    build(1, 1, n);
    cin >> q;
    ll k, l, r, x;
    for (int i = 1; i <= q; i++) {
        cin >> k;
        if (k == 1) {
            cin >> k >> l >> r >> x;
            update_1(1, k, l, r, x);
        } else if (k == 2){
            cin >> l >> r;
            update_2(1, l, r);
        } else if (k == 3) {
            cin >> l >> r;
            update_3(1, l, r);
        } else {
            cin >> l >> r;
            cout<<query(1, l, r)<<endl;
        }
    }

    return 0;
}
