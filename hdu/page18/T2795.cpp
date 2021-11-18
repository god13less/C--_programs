//
// Created by wang on 2021/7/21.
//

#include <bits\stdc++.h>

#define endl "\n"
using namespace std;
typedef long long ll;
const double PI = acos(-1.0);
const double EI = exp(1.0);
const int inf = 0x3f3f3f3f;
const int maxn = 200005;
#define lson rt<<1
#define rson rt<<1|1
int h, w;
struct node {
    int l, r, w;
} tree[maxn << 2];

void build(int rt, int l, int r) {
    tree[rt].l = l;
    tree[rt].r = r;
    if (l == r) {
        tree[rt].w = w;
        return;
    }
    int mid = (l + r) >> 1;
    build(lson, l, mid);
    build(rson, mid + 1, r);
    tree[rt].w = max(tree[lson].w, tree[rson].w);
}

int query(int rt, int p) {
    if (tree[rt].l == tree[rt].r) {
        tree[rt].w -= p;
        return tree[rt].l;
    }
    int mid = (tree[rt].l + tree[rt].r) >> 1;
    int ans;
    if (p <= tree[rt].w) {
        if (p <= tree[lson].w) {
            ans = query(lson, p);
        } else {
            ans = query(rson, p);
        }
    }
    tree[rt].w = max(tree[lson].w, tree[rson].w);
    return ans;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int q, x;
    while (cin >> h >> w >> q) {
        if (h > q) {
            h = q;
        }
        build(1, 1, h);
        for (int i = 1; i <= q; i++) {
            cin >> x;
            if (x > tree[1].w) {
                cout << -1 << endl;
            } else {
                cout << query(1, x) << endl;
            }
        }
    }
    return 0;
}