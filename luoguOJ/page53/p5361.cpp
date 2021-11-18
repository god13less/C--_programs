#include <bits/stdc++.h>

#define inf 0x3f3f3f3f
#define N 10005
#define M 100005
#define getchar nc
using namespace std;

inline char nc() {
    static char buf[100000], *p1 = buf, *p2 = buf;
    return p1 == p2 && (p2 = (p1 = buf) + fread(buf, 1, 100000, stdin), p1 == p2) ? EOF : *p1++;
}

inline int read() {
    register int x = 0, f = 1;
    register char ch = getchar();
    while (ch < '0' || ch > '9') {
        if (ch == '-')f = -1;
        ch = getchar();
    }
    while (ch >= '0' && ch <= '9')x = (x << 3) + (x << 1) + ch - '0', ch = getchar();
    return x * f;
}

inline void write(register int x) {
    if (!x)putchar('0');
    if (x < 0)x = -x, putchar('-');
    static int sta[20];
    register int tot = 0;
    while (x)sta[tot++] = x % 10, x /= 10;
    while (tot)putchar(sta[--tot] + 48);
}

struct node {
    int to, next;
} e[M << 1];
int head[N], cnt;

inline void add(int u, int v) {
    e[++cnt] = (node) {v, head[u]};
    head[u] = cnt;
}

int T, n, m, du[N], ans[N], del[N];
int t[N << 3];

inline int Min(int x, int y) {
    return du[x] < du[y] ? x : y;
}

inline void build(int x, int l, int r) {
    if (l == r) {
        t[x] = l;
        return;
    }
    int mid = l + r >> 1;
    build(x << 1, l, mid);
    build(x << 1 | 1, mid + 1, r);
    t[x] = Min(t[x << 1], t[x << 1 | 1]);
}

inline void modify(int x, int l, int r, int pos) {
    if (l == r)
        return;
    int mid = l + r >> 1;
    if (pos <= mid)
        modify(x << 1, l, mid, pos);
    else
        modify(x << 1 | 1, mid + 1, r, pos);
    t[x] = Min(t[x << 1], t[x << 1 | 1]);
}

int main() {
    T = read();
    while (T--) {
        for (int i = 1; i <= n; ++i)
            ans[i] = del[i] = du[i] = 0;
        memset(head, 0, sizeof(int) * (cnt + 1));
        cnt = 0;
        n = read(), m = read();
        int tim = 0, mx = 0, pos = 0;
        for (int i = 1; i <= m; ++i) {
            int u = read(), v = read();
            add(u, v), add(v, u);
            ++du[u], ++du[v];
        }
        build(1, 1, n);
        while (19260817) {
            int x = t[1];
            if (du[x] == inf)
                break;
            if (du[x] >= mx)
                mx = du[x], pos = tim;
            ans[x] = 1, del[x] = ++tim, du[x] = inf;
            modify(1, 1, n, x);
            for (int i = head[x]; i; i = e[i].next) {
                int v = e[i].to;
                if (del[v])
                    continue;
                del[v] = tim, du[v] = inf;
                modify(1, 1, n, v);
                for (int j = head[v]; j; j = e[j].next) {
                    int t = e[j].to;
                    if (del[t])
                        continue;
                    --du[t];
                    modify(1, 1, n, t);
                }
            }
        }
        vector<int> P, Q;
        for (int i = 1; i <= n; ++i) {
            if (del[i] > pos)
                P.push_back(i);
            if (ans[i])
                Q.push_back(i);
        }
        write(P.size()), putchar(' ');
        for (int i = 0; i < P.size(); ++i)
            write(P[i]), putchar(' ');
        puts("");
        write(Q.size()), putchar(' ');
        for (int i = 0; i < Q.size(); ++i)
            write(Q[i]), putchar(' ');
        puts("");
    }
    return 0;
}