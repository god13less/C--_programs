#include<bits/stdc++.h>

using namespace std;
const int maxn = 101005;
int N, M, root;

inline int read() {
    int ret = 0, f = 1;
    char ch = getchar();
    while (ch < '0' || ch > '9') {
        if (ch == '-')f = -f;
        ch = getchar();
    }
    while (ch <= '9' && ch >= '0')ret = ret * 10 + ch - '0', ch = getchar();
    return ret * f;
}

struct node {
    int size, fa, ch[2], rev;
} t[maxn];

inline void pushup(int x) {
    t[x].size = t[t[x].ch[0]].size + t[t[x].ch[1]].size + 1;
}

inline void pushdown(int x) {
    if (t[x].rev) {
        swap(t[x].ch[0], t[x].ch[1]);
        t[t[x].ch[0]].rev ^= 1;
        t[t[x].ch[1]].rev ^= 1;
        t[x].rev = 0;
    }
}

void build(int l, int r, int x) {
    if (l > r) return;
    int mid = (r - l >> 1) + l;
    if (mid < x) t[x].ch[0] = mid; else t[x].ch[1] = mid;
    t[mid].fa = x;
    t[mid].size = 1;
    if (l == r) return;
    build(l, mid - 1, mid);
    build(mid + 1, r, mid);
    pushup(mid);
}

inline void rotate(int x, int &goal) {
    int y = t[x].fa;
    int z = t[y].fa;
    int k = t[y].ch[1] == x;
    if (y == goal) {
        goal = x;
    } else {
        t[z].ch[t[z].ch[1] == y] = x;
    }
    t[t[x].ch[k ^ 1]].fa = y;
    t[y].fa = x;
    t[x].fa = z;
    t[y].ch[k] = t[x].ch[k ^ 1];
    t[x].ch[k ^ 1] = y;
    pushup(y);
    pushup(x);
}

void splay(int x, int &goal) {
    while (x != goal) {
        int y = t[x].fa, z = t[y].fa;
        if (y != goal) {
            (t[z].ch[0] == y) ^ (t[y].ch[0] == x) ? rotate(x, goal) : rotate(y, goal);
        }
        rotate(x, goal);
    }
}

void rever(int L, int R) {
    splay(L, root);
    splay(R, t[L].ch[1]);
    t[t[R].ch[0]].rev ^= 1;
}

int query(int x, int k) {
    pushdown(x);
    int sum = t[t[x].ch[0]].size + 1;
    if (sum == k)return x;
    return (sum > k ? query(t[x].ch[0], k) : query(t[x].ch[1], k - sum));
}

void print(int x) {
    pushdown(x);
    t[x].ch[0] && (print(t[x].ch[0]), 0);
    if (x >= 2 && x <= N + 1)printf("%d ", x - 1);
    t[x].ch[1] && (print(t[x].ch[1]), 0);
}

int main() {
    N = read();
    M = read();
    root = (N + 3) / 2;
    build(1, N + 2, root);
    for (int i = 1; i <= M; i++) {
        int L = read(), R = read();
        L = query(root, L);
        R = query(root, R + 2);
        rever(L, R);
    }
    print(root);
    return 0;
}

