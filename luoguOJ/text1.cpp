#include <bits/stdc++.h>

using namespace std;
const int N = 100005;
struct splay_tree {
    int ff, cnt, ch[2], val, size,flag;
} t[N];
int root, tot;

void update(int x) {
    t[x].size = t[t[x].ch[0]].size + t[t[x].ch[1]].size + t[x].cnt;
}


void rotate(int x) {
    int y = t[x].ff;
    int z = t[y].ff;
    int k = (t[y].ch[1] == x);
    t[z].ch[(t[z].ch[1] == y)] = x;
    t[x].ff = z;
    t[y].ch[k] = t[x].ch[k ^ 1];
    t[t[x].ch[k ^ 1]].ff = y;
    t[x].ch[k ^ 1] = y;
    t[y].ff = x;
    update(y);
    update(x);
}

void splay(int x, int rt) {
    while (t[x].ff != rt) {
        int y = t[x].ff, z = t[y].ff;
        if (z != rt) {
            (t[z].ch[0] == y) ^ (t[y].ch[0] == x) ? rotate(x) : rotate(y);
        }
        rotate(x);
    }
    if (rt == 0) {
        root = x;
    }
}

void find(int x) {
    int u = root;
    if (!u) {
        return;
    }
    while (t[u].ch[x > t[u].val] && x != t[u].val) {
        u = t[u].ch[x > t[u].val];
    }
    splay(u, 0);
}

void insert(int x) {
    int u = root, ff = 0;
    while (u && t[u].val != x) {
        ff = u;
        u = t[u].ch[x > t[u].val];
    }
    if (u) {
        t[u].cnt++;
    } else {
        u = ++tot;
        if (ff) {
            t[ff].ch[x > t[ff].val] = u;
            t[u].ch[0] = t[u].ch[1] = 0;
            t[tot].ff = ff;
            t[tot].val = x;
            t[tot].cnt = 1;
            t[tot].size = 1;
        }
        splay(u, 0);
    }
}

int Next(int x, int f) {//查找x的前驱（0）或后继（1）
    find(x);
    int u = root;
    if (t[u].val > x && f) {
        return u;
    }
    if (t[u].val < x && !f) {
        return u;
    }
    u = t[u].ch[f];
    while (t[u].ch[f ^ 1]) {
        u = t[u].ch[f ^ 1];
    }
    return u;
}

void Delete(int x) {
    int last = Next(x, 0);
    int Net = Next(x, 1);
    splay(last, 0);
    splay(Net, last);
    int del = t[Net].ch[0];
    if (t[del].cnt > 1) {
        t[del].cnt--;
        splay(del, 0);
    } else {
        t[Net].ch[0] = 0;
    }
}

int kth(int x) {
    int u = root;
    while (t[u].size < x) {
        return 0;
    }
    while (1) {
        int y = t[u].ch[0];
        if (x > t[y].size + t[u].cnt) {
            x -= t[y].size + t[u].cnt;
            u = t[u].ch[1];
        } else if (t[y].size >= x) {
            u = y;
        } else {
            return t[u].val;
        }
    }
}
void in(int x){
    if (t[x].ch[0]) {
        in(t[x].ch[0]);
    }
    cout << t[x].val << ' ';
    if (t[x].ch[1]) {
        in(t[x].ch[1]);
    }
}

int main() {
    int n;
    cin >> n;
    insert(1e9);
    insert(1e9);
    insert(-1e9);
    while (n--) {
        int opt, x;
        cin >> opt >> x;
        if (opt == 1) {
            insert(x);
        }
        if (opt == 2) {
            Delete(x);
        }
        if (opt == 3) {
            find(x);
            cout << t[t[root].ch[0]].size << endl;
        }
        if (opt == 4) {
            cout << kth(x + 1) << endl;
        }
        if (opt == 5) {
            cout << t[Next(x, 0)].val << endl;
        }
        if (opt == 6) {
            cout << t[Next(x, 1)].val << endl;
        }
        if (opt == 7) {
            in(x);
        }
        if (opt == 8) {
            for (int i = 1; i <= x; i++) {
                cout << t[i].val << ' ';
            }
        }
    }
    return 0;
}
