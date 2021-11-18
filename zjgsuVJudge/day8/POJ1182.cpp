//
// Created by wang on 2021/2/18.
//

#include <cstdio>

#define MAXN 150050

using namespace std;

int pre[MAXN];

void Make(int n) {
    for (int i = 0; i <= 3 * n; i++) {
        pre[i] = i;
    }
}

int Find(int s) {
    if (pre[s] != s) {
        return pre[s] = Find(pre[s]);
    } else return pre[s];
}

void Union(int s, int e) {
    int u = Find(s);
    int v = Find(e);
    if (u == v) {
        return;
    }
    pre[v] = u;
}

int main() {
    int n, k;
    scanf("%d %d", &n, &k);
    Make(n);
    int ans = 0;
    for (int i = 1; i <= k; i++) {
        int t, x, y;
        scanf("%d %d %d", &t, &x, &y);
        if (x > n || y > n) {
            ans++;
            continue;
        }
        if (t == 2 && x == y) {
            ans++;
            continue;
        }
        if (t == 1) {
            if (Find(y) == Find(x + 2 * n) || Find(x) == Find(y + 2 * n)) {
                ans++;
                continue;
            }
            Union(x, y);
            Union(x + n, y + n);
            Union(x + 2 * n, y + 2 * n);
        } else {
            if (Find(x) == Find(y) || Find(x) == Find(y + 2 * n)) {
                ans++;
                continue;
            }
            Union(x + 2 * n, y);
            Union(x + n, y + 2 * n);
            Union(x, y + n);
        }
    }
    printf("%d\n", ans);
    return 0;
}
