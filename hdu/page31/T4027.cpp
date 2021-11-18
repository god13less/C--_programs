//
// Created by wang on 2021/7/28.
//
//TLE
#include <bits\stdc++.h>

using namespace std;
typedef long long ll;
const int maxn = 1e5 + 10;

struct node {
    ll l, r, sum;
} T[maxn << 2];

void build(ll rt, ll l, ll r) {
    T[rt].l = l;
    T[rt].r = r;
    if (l == r) {
        cin >> T[rt].sum;
        return;
    }
    ll mid = (l + r) >> 1;
    build(rt << 1, l, mid);
    build(rt << 1 | 1, mid + 1, r);
    T[rt].sum = T[rt << 1].sum + T[rt << 1 | 1].sum;
}

void update(ll rt, ll L, ll R) {
    if (T[rt].l == L && T[rt].r == R) {
        if (T[rt].sum == T[rt].r - T[rt].l + 1) {
            return;
        }
    }
    if (T[rt].l == T[rt].r) {
        T[rt].sum = (ll)sqrt(T[rt].sum);
        return;
    }
    ll mid = (T[rt].r + T[rt].l) >> 1;
    if (R <= mid) {
        update(rt << 1, L, R);
    } else if (L > mid) {
        update(rt << 1 | 1, L, R);
    } else {
        update(rt << 1, L, mid);
        update(rt << 1 | 1, mid + 1, R);
    }
    T[rt].sum = T[rt << 1].sum + T[rt << 1 | 1].sum;
}

ll query(ll rt, ll L, ll R) {
    if (T[rt].l == L && T[rt].r == R) {
        return T[rt].sum;
    }
    ll mid = (T[rt].l + T[rt].r) >> 1;
    if (R <= mid) {
        return query(rt << 1, L, R);
    } else if (L > mid) {
        return query(rt << 1 | 1, L, R);
    } else {
        return query(rt << 1, L, mid) + query(rt << 1 | 1, mid + 1, R);
    }

}

int main() {
    ll n, m;
    ll t, x, y;
    ll k = 1;
    while (cin >> n) {
        build(1, 1, n);
        cin >> m;
        cout << "Case #" << k << ':' << endl;
        for (int i = 1; i <= m; i++) {
            cin >> t >> x >> y;
            if (x > y) {
                ll tem = x;
                x = y;
                y = tem;
            }
            if (t == 1) {
                cout << query(1, x, y) << endl;
            } else {
                update(1, x, y);
            }
        }
        cout << endl;
    }
    return 0;
}