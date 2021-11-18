//
// Created by wang on 2021/7/21.
//
// TLE

#include <bits\stdc++.h>

#define endl "\n"
using namespace std;
typedef long long ll;

struct node {
    int left, right, sum, mark;
} str[300050];

void build(int l, int r, int n) {
    str[n].left = l;
    str[n].right = r;
    str[n].mark = 0;
    str[n].sum = 1;
    if (l == r) {
        return;
    }
    int mid = (l + r) / 2;
    build(l, mid, 2 * n);
    build(mid + 1, r, 2 * n + 1);
}

void pushUp(int n) {
    str[n].sum = str[2 * n].sum + str[2 * n + 1].sum;
}

void pushDown(int n) {
    if (str[n].mark != 0) {
        str[2 * n].mark = str[n].mark;
        str[2 * n + 1].mark = str[n].mark;

        str[2 * n].sum = str[n].mark * (str[2 * n].right - str[2 * n].left + 1);
        str[2 * n + 1].sum = str[n].mark * (str[2 * n + 1].right - str[2 * n + 1].left + 1);
        str[n].mark = 0;
    }
}

void update(int l, int r, int w, int n) {
    if (l > str[n].right || r < str[n].left) {
        return;
    }
    if (l <= str[n].left && r >= str[n].right) {
        str[n].mark = w;
        str[n].sum = w * (str[n].right - str[n].left + 1);
        return;
    }
    pushDown(n);
    int mid = (str[n].left + str[n].right) / 2;
    if (l <= mid) {
        update(l, r, w, 2 * n);
    }
    if (r > mid) {
        update(l, r, w, 2 * n + 1);
    }
    pushUp(n);
}

int query(int l, int r, int n) {
    if (l <= str[n].left && str[n].right <= r) {
        return str[n].sum;
    } else {
        int ans = 0;
        int mid = (str[n].left + str[n].right) / 2;
        if (l < mid) {
            ans += query(l, r, 2 * n);
        }
        if (r > mid) {
            ans += query(l, r, 2 * n + 1);
        }
        return ans;
    }
}

int main() {
    int t, n, q;
    cin >> t;
    for (int j = 1; j <= t; j++) {
        cin >> n >> q;
        build(1, n, 1);
        update(1, n, 1, 1);
        for (int i = 1; i <= q; i++) {
            int l, r, v;
            cin >> l >> r >> v;
            update(l, r, v, 1);
        }
        cout << "Case " << j << ": The total value of the hook is " << str[1].sum << '.' << endl;
    }
    return 0;
}