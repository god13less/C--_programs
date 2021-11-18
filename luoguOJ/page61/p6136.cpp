//
// Created by wang on 2021/9/23.
//
#include <bits/stdc++.h>

using namespace std;
const int N = 4e6 + 10;
const int INF = 2e9;

int n, m;
struct node {
    int l, r;
    int key, val;
    int cnt, size;
} tr[N];
int root, idx;

void pushup(int p) {
    tr[p].size = tr[tr[p].l].size + tr[tr[p].r].size + tr[p].cnt;
}

int add_node(int key) {
    tr[++idx].key = key;
    tr[idx].val = rand();
    tr[idx].cnt = 1;
    tr[idx].size = 1;
    return idx;
}

void lspin(int &p) {
    int q = tr[p].r;
    tr[p].r = tr[q].l;
    tr[q].l = p;
    p = q;
    pushup(tr[p].l);
    pushup(p);
}

void rspin(int &p) //right
{
    int q = tr[p].l;
    tr[p].l = tr[q].r;
    tr[q].r = p;
    p = q;
    pushup(tr[p].r);
    pushup(p);
}

void build() {
    tr[0] = {0, 0, 0, 0, 0, 0};
    //两个哨兵
    add_node(-INF);
    add_node(INF);
    root = 1, tr[1].r = 2;
    pushup(root);
    if (tr[1].val < tr[2].val) {
        lspin(root);
    }
}

void insert(int &p, int key) {
    if (!p) {
        p = add_node(key);
    } else if (tr[p].key == key) {
        tr[p].cnt++;
    } else if (tr[p].key > key) {
        insert(tr[p].l, key);
        if (tr[tr[p].l].val > tr[p].val) {
            rspin(p);
        }
    } else {
        insert(tr[p].r, key);
        if (tr[tr[p].r].val > tr[p].val) {
            lspin(p);
        }
    }
    pushup(p);
}

void remove(int &p, int key) {
    if (!p) {
        return;
    }
    if (tr[p].key == key) {
        if (tr[p].cnt > 1) {
            tr[p].cnt--;
        } else if (tr[p].l || tr[p].r) {
            if (!tr[p].r || tr[tr[p].l].val > tr[tr[p].r].val) {
                rspin(p);
                remove(tr[p].r, key);
            } else {
                lspin(p);
                remove(tr[p].l, key);
            }
        } else {
            p = 0;
        }
    } else if (tr[p].key > key) {
        remove(tr[p].l, key);
    } else {
        remove(tr[p].r, key);
    }
    pushup(p);
}

int get_rank_by_key(int p, int key) {
    if (!p) {
        return 1;
    }
    if (tr[p].key == key) {
        return tr[tr[p].l].size + 1;
    }
    if (tr[p].key > key) {
        return get_rank_by_key(tr[p].l, key);
    } else {
        return get_rank_by_key(tr[p].r, key) + tr[tr[p].l].size + tr[p].cnt;
    }
}

int get_key_by_rank(int p, int rnk) {
    if (!p) {
        return 0;
    }
    if (tr[tr[p].l].size >= rnk) {
        return get_key_by_rank(tr[p].l, rnk);
    }
    if (tr[tr[p].l].size + tr[p].cnt >= rnk) {
        return tr[p].key;
    }
    return get_key_by_rank(tr[p].r, rnk - tr[tr[p].l].size - tr[p].cnt);
}

int get_prev(int p, int key) {
    if (!p) {
        return -INF;
    }
    if (tr[p].key >= key) {
        return get_prev(tr[p].l, key);
    }
    return max(tr[p].key, get_prev(tr[p].r, key));
}

int get_next(int p, int key) {
    if (!p) {
        return INF;
    }
    if (tr[p].key <= key) {
        return get_next(tr[p].r, key);
    }
    return min(tr[p].key, get_next(tr[p].l, key));
}

int main() {
    build();
    cin >> n >> m;
    while (n--) {
        int x;
        cin >> x;
        insert(root, x);
    }
    int last = 0;
    int res = 0;
    while (m--) {
        int op, x;
        cin >> op >> x;
        x ^= last;
        switch (op) {
            case 1:
                insert(root, x);
                break;
            case 2:
                remove(root, x);
                break;
            case 3:
                last = get_rank_by_key(root, x) - 1;
                res ^= last;
                break;
            case 4:
                last = get_key_by_rank(root, x + 1);
                res ^= last;
                break;
            case 5:
                last = get_prev(root, x);
                res ^= last;
                break;
            case 6:
                last = get_next(root, x);
                res ^= last;
                break;
        }
    }
    cout<<res<<endl;
    return 0;
}