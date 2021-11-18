//主席树模板题

#include <iostream>
#include <algorithm>

#define endl "\n"
using namespace std;
typedef long long ll;
const int maxn = 2e5 + 5;

struct node {
    int l, r, sum;
} hjt[maxn * 40];
int cnt, root[maxn];

void update(int l, int r, int pre, int &now, int p) {
    hjt[++cnt] = hjt[pre];
    now = cnt;
    hjt[now].sum++;
    if (l == r) {
        return;
    }
    int mid = (l + r) >> 1;
    if (p <= mid) {
        update(l, mid, hjt[pre].l, hjt[now].l, p);
    } else {
        update(mid + 1, r, hjt[pre].r, hjt[now].r, p);
    }
}

int query(int l, int r, int L, int R, int k) {
    if (l == r) {
        return l;
    }
    int mid = (l + r) >> 1;
    int tem = hjt[hjt[R].l].sum - hjt[hjt[L].l].sum;
    if (k <= tem) {
        return query(l, mid, hjt[L].l, hjt[R].l, k);
    } else {
        return query(mid + 1, r, hjt[L].r, hjt[R].r, k - tem);
    }
}

int n, m;
int a[maxn];
int b[maxn];

int main() {
    std::ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        b[i] = a[i];
    }

    sort(b + 1, b + n + 1);
    ll num = unique(b + 1, b + n + 1) - b - 1;
    for (int i = 1; i <= n; i++) {
        a[i] = lower_bound(b + 1, b + num + 1, a[i]) - b;
        update(1, n, root[i - 1], root[i], a[i]);
    }
    int l, r, k;
    for (int i = 1; i <= m; i++) {
        cin >> l >> r >> k;
        cout << b[query(1, n, root[l-1], root[r], k)] << endl;
    }


    return 0;
}