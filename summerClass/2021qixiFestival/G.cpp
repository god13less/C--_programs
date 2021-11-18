//
// Created by wang on 2021/8/14.
//
#include<bits/stdc++.h>

#define inf 0x3f3f3f3f

using namespace std;
typedef long long ll;
#define ls k<<1
#define rs k<<1|1
const int N = 1000005;

inline int read() {
    int x = 0;
    char ch;
    for (ch = getchar(); !isdigit(ch); ch = getchar());
    for (; isdigit(ch); ch = getchar())x = (x << 1) + (x << 3) + (ch ^ 48);
    return x;
}

struct node {
    int l, r, lzy;
    int sum;
} tr[N << 2];

int a[N], n, m;

void pushup(int k) {
    tr[k].sum = tr[ls].sum | tr[rs].sum;
}

void build(int k, int l, int r) {
    tr[k].l = l;
    tr[k].r = r;
    tr[k].lzy = 0;
    if (l == r) {
        tr[k].sum = read();
        return;
    }
    int mid = (l + r) >> 1;
    build(ls, l, mid);
    build(rs, mid + 1, r);
    pushup(k);
}

void pushdown(int k) {
    if (tr[k].lzy == 0) {
        return;
    }
    int x = tr[k].lzy;
    tr[ls].lzy = tr[rs].lzy = tr[ls].sum = tr[rs].sum = x;
    tr[k].lzy = 0;
}

int query(int k, int l, int r) {
    if (tr[k].l >= l && tr[k].r <= r) {
        return tr[k].sum;
    }
    int mid = (tr[k].l + tr[k].r) >> 1;
    pushdown(k);
    int res=0;
    if (l <= mid) res |= query(ls, l, r);
    if (r > mid) res |= query(rs, l, r);
    return res;
}

void update(int k, int l, int r, int lzy) {
    if (tr[k].l >= l && tr[k].r <= r) {
        tr[k].sum = lzy;
        tr[k].lzy = lzy;
        return;
    }
    pushdown(k);
    int mid = (tr[k].l + tr[k].r) >> 1;
    if (l <= mid) update(ls, l, r, lzy);
    if (r > mid) update(rs, l, r, lzy);
    pushup(k);
}


int main() {
    n = read();
    m = read();
    build(1, 1, n);
    while (m--) {
        int op;
        op=read();
        if (op == 2) {
            int l, r, x;
            l=read();
            r=read();
            x=read();
            update(1, l, r, x);
        } else {
            int l, r;
            l=read();
            r=read();
            int ans = query(1, l, r);
            printf("%d\n", ans);
        }
    }

    return 0;
}