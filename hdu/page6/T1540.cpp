//
// Created by wang on 2021/7/26.
//
//线段树的区间合并

#include <iostream>
#include <stack>
#define inf 0x3f3f3f3f

using namespace std;
typedef long long ll;
const ll maxn = 50000 + 10;
stack<ll> sta;
struct node {
    ll l, r;
    ll ls, rs, ms;
} tree[maxn << 2];

void build(ll l,ll r,ll rt){
    tree[rt].l = l;
    tree[rt].r = r;
    tree[rt].ls = tree[rt].rs = tree[rt].ms = r - l + 1;
    if (l == r) {
        return;
    }
    ll mid = (l + r) >> 1;
    build(l, mid, rt << 1);
    build(mid + 1, r, rt << 1 | 1);
}

void update(ll rt,ll x,ll bo){
    if (tree[rt].l == tree[rt].r) {
        if (bo == 1) {
            tree[rt].ls = tree[rt].rs = tree[rt].ms = 0;
        } else {
            tree[rt].ls = tree[rt].rs = tree[rt].ms = 1;
        }
        return;
    }
    ll mid = (tree[rt].l + tree[rt].r) >> 1;
    if (x <= mid) {
        update(rt << 1, x, bo);
    } else {
        update(rt << 1 | 1, x, bo);
    }
    tree[rt].ls = tree[rt << 1].ls;
    tree[rt].rs = tree[rt << 1 | 1].rs;
    tree[rt].ms = max(max(tree[rt << 1].ms, tree[rt << 1 | 1].ms), tree[rt << 1].rs + tree[rt << 1 | 1].ls);
    if (tree[rt << 1].r - tree[rt << 1].l + 1 == tree[rt<<1].ls) {
        tree[rt].ls += tree[rt << 1 | 1].ls;
    }
    if (tree[rt << 1 | 1].rs == tree[rt << 1 | 1].r - tree[rt << 1 | 1].l + 1) {
        tree[rt].rs+=tree[rt<<1].rs;
    }
}

ll query(ll rt, ll x){
    if (tree[rt].l == tree[rt].r || tree[rt].ms == 0 || tree[rt].ms == tree[rt].r - tree[rt].l + 1) {
        return tree[rt].ms;
    }
    ll mid = (tree[rt].r + tree[rt].l) >> 1;
    if (x <= mid) {
        if (x >= tree[rt << 1].r - tree[rt << 1].rs + 1) {
            return query(rt << 1, x) + query(rt << 1 | 1, mid + 1);
        } else {
            return query(rt << 1, x);
        }
    } else {
        if (x <= tree[rt << 1 | 1].l + tree[rt << 1 | 1].ls - 1) {
            return query(rt << 1 | 1, x) + query(rt << 1, mid);
        } else {
            return query(rt << 1 | 1, x);
        }
    }
}

int main() {
    ll n,m,x;
    string str;
    while (cin >> n >> m) {
        build(1, n, 1);
        for (int i = 1; i <= m; i++) {
            cin >> str;
            if (str == "D") {
                cin >> x;
                update(1, x, 1);
                sta.push(x);
            } else if (str == "Q") {
                cin >> x;
                cout << query(1, x) << endl;
            } else {
                update(1, sta.top(), 0);
                sta.pop();
            }
        }
        while (!sta.empty()) {
            sta.pop();
        }
    }
    return 0;
}