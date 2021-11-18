//
// Created by wang on 2021/7/22.
//

#include <iostream>
#include <algorithm>
#include <map>

using namespace std;
typedef long long ll;

#define maxn 200050
struct node {
    int w, l, r;
} tree[maxn << 2];

void build(int rt, int l, int r) {
    tree[rt].l = l;
    tree[rt].r = r;
    if (tree[rt].l == tree[rt].r) {
        tree[rt].w = 0;
        return;
    }
    int mid = (l + r) >> 1;
    build(rt << 1, l, mid);
    build(rt << 1 | 1, mid + 1, r);
    tree[rt].w = tree[rt >> 1].w + tree[rt >> 1 | 1].w;
}

//插入与删除操作，v==1为插入，v==-1为删除
void update(int rt, int num, int v) {
    if (tree[rt].r == tree[rt].l && num == tree[rt].r) {
        tree[rt].w += v;
        return;
    }
    int mid = (tree[rt].l + tree[rt].r) >> 1;
    if (num <= mid) {
        update(rt << 1, num, v);
    } else {
        update(rt << 1 | 1, num, v);
    }
    tree[rt].w = tree[rt << 1].w + tree[rt << 1 | 1].w;
}

//查询第K大元素
int query_Kth(int rt, int k) {
    if (tree[rt].l == tree[rt].r) {
        return tree[rt].r;
    }
    if (tree[rt << 1].w >= k) {
        return query_Kth(rt << 1, k);
    } else {
        return query_Kth(rt << 1 | 1, k - tree[rt << 1].w);
    }
}

int query(int rt, int l, int r) {
    if (l <= tree[rt].l && r >= tree[rt].r) {
        return tree[rt].w;
    }
    int ans = 0;
    int mid = (tree[rt].l + tree[rt].r) >> 1;
    if (l <= mid) {
        ans += query(rt << 1, l, r);
    }
    if (r > mid) {
        ans += query(rt << 1 | 1, l, r);
    }
    return ans;
}

//查询x的排名
int query_rank(int x) {
    if (x <= 1) {
        return 1;
    }
    return query(1, 1, x - 1) + 1;
}

//查询前驱
int find_pre(int rt) {
    if (tree[rt].r == tree[rt].l) {
        return tree[rt].r;
    }
    if (tree[rt].w) {
        return find_pre(rt << 1 | 1);
    } else {
        return find_pre(rt << 1);
    }
}
int pre(int rt,int num){
    if (tree[rt].r < num) {
        if (tree[rt].w) {
            return find_pre(rt);
        }
        return 0;
    }
    int ans=0;
    int mid = (tree[rt].l + tree[rt].r) >> 1;
    if (mid < num - 1 && tree[rt].w && (ans = pre(rt << 1 | 1, num))) {
        return ans;
    }
    return pre(rt << 1, num);
}

//查询后继
int find_next(int rt){
    if (tree[rt].r == tree[rt].l) {
        return tree[rt].l;
    }
    if (tree[rt].w) {
        return find_pre(rt << 1);
    } else {
        return find_pre(rt << 1 | 1);
    }
}
int next(int rt, int num){
    if (num < tree[rt].l) {
        if (tree[rt].w) {
            return find_next(rt);
        }
        return 0;
    }
    int ans=0;
    int mid = (tree[rt].l + tree[rt].r) >> 1;
    if (num < mid && tree[rt << 1].w && (ans = next(rt << 1, num))) {
        return ans;
    }
    return next(rt << 1 | 1, num);
}


ll arr[maxn], lsh[maxn];
int q[maxn];

int main() {
    int m, n;
    map<ll, ll> ma;
    while (cin >> m >> n) {
        build(1, 1, m);
        for (int i = 1; i <= m; i++) {
            cin >> arr[i];
            lsh[i] = arr[i];
        }
        for (int i = 1; i <= n; i++) {
            cin >> q[i];
        }

        for (int i = 1; i <= m; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
        //离散化处理
        sort(lsh + 1, lsh + m + 1);
        ll cnt = unique(lsh + 1, lsh + m + 1) - lsh - 1;
        for (int i = 1; i <= cnt; i++) {
            ma[i] = lsh[i];
        }
        for (int i = 1; i <= m; i++) {
            arr[i] = lower_bound(lsh + 1, lsh + cnt + 1, arr[i]) - lsh;
        }

        for (int i = 1; i <= m; i++) {
            cout << arr[i] << " ";
        }
        cout << endl << endl;

        int x = 1;
        for (int i = 1; i <= m; i++) {
            update(1, arr[i], 1);
            while (i == q[x]) {
                cout << ma[query_Kth(1, x)] << endl;
                x++;
            }
        }
        for (int i = 1; i <= m; i++) {
            cout << next(1,i) << endl;
        }
    }
    return 0;
}
