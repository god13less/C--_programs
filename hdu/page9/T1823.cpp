//
// Created by wang on 2021/7/28.
//
//二维线段树模板题

#include <bits\stdc++.h>

#define endl "\n"
using namespace std;
typedef long long ll;
const double PI = acos(-1.0);
const double EI = exp(1.0);
const int inf = 0x3f3f3f3f;
const int maxn = 2050;

struct sub_node {
    int la, ra, maxL;
};

struct node {
    int l, r;
    sub_node T[maxn];
} TT[maxn];

void sub_build(int rt, int sub_rt, int la, int ra) {
    TT[rt].T[sub_rt].la = la;
    TT[rt].T[sub_rt].ra = ra;
    TT[rt].T[sub_rt].maxL = -1;
    if (la == ra) {
        return;
    }
    int mid = (la + ra) >> 1;
    sub_build(rt, sub_rt << 1, la, mid);
    sub_build(rt, sub_rt << 1 | 1, mid + 1, ra);
}

void build(int rt, int l, int r, int la, int ra) {
    TT[rt].l = l;
    TT[rt].r = r;
    sub_build(rt, 1, la, ra);
    if (l == r) {
        return;
    }
    int mid = (l + r) >> 1;
    build(rt << 1, l, mid, la, ra);
    build(rt << 1|1, mid + 1, r, la, ra);
}

void sub_update(int rt, int sub_rt, int active, int love) {
    if (TT[rt].T[sub_rt].la == TT[rt].T[sub_rt].ra) {
        TT[rt].T[sub_rt].maxL = max(TT[rt].T[sub_rt].maxL, love);
        return;
    }
    int mid = (TT[rt].T[sub_rt].la + TT[rt].T[sub_rt].ra) >> 1;
    if (active <= mid) {
        sub_update(rt, sub_rt << 1, active, love);
    } else {
        sub_update(rt, sub_rt << 1 | 1, active, love);
    }
    TT[rt].T[sub_rt].maxL = max(TT[rt].T[sub_rt].maxL, love);
}

void update(int rt, int height, int active, int love) {
    sub_update(rt, 1, active, love);
    if (TT[rt].l == TT[rt].r) {
        return;
    }
    int mid = (TT[rt].l + TT[rt].r) >> 1;
    if (height <= mid) {
        update(rt << 1, height, active, love);
    } else {
        update(rt << 1 | 1, height, active, love);
    }
}

int sub_query(int rt, int sub_rt, int a1, int a2) {
    if (TT[rt].T[sub_rt].la == a1 && TT[rt].T[sub_rt].ra == a2) {
        return TT[rt].T[sub_rt].maxL;
    }
    int mid = (TT[rt].T[sub_rt].la + TT[rt].T[sub_rt].ra) >> 1;
    if (a2 <= mid) {
        return sub_query(rt, sub_rt << 1, a1, a2);
    } else if (a1 > mid) {
        return sub_query(rt, sub_rt << 1 | 1, a1, a2);
    } else {
        return max(sub_query(rt, sub_rt << 1, a1, mid), sub_query(rt, sub_rt << 1 | 1, mid + 1, a2));
    }
}

int query(int rt, int h1, int h2, int a1, int a2) {
    if (TT[rt].l == h1 && TT[rt].r == h2) {
        return sub_query(rt, 1, a1, a2);
    }
    int mid = (TT[rt].r + TT[rt].l) >> 1;
    if (h2 <= mid) {
        return query(rt << 1, h1, h2, a1, a2);
    } else if (h1 > mid) {
        return query(rt << 1 | 1, h1, h2, a1, a2);
    } else {
        return max(query(rt << 1, h1, mid, a1, a2), query(rt << 1 | 1, mid + 1, h2, a1, a2));
    }
}


int main() {
    int n, h1, h2, a1, a2, l;
    double aa1, aa2, L;
    string str;
    while (cin >> n && n != 0) {
        build(1, 100, 200, 0, 1000);
        for (int i = 1; i <= n; i++) {
            cin >> str;
            if (str == "I") {
                cin >> h1 >> aa1 >> L;
                a1 = int(aa1 * 10);
                l = int(L * 10);
                update(1, h1, a1, l);
            } else {
                cin >> h1 >> h2 >> aa1 >> aa2;
                if (h1 > h2) {
                    int tem = h1;
                    h1 = h2;
                    h2 = tem;
                }
                a1 = int(aa1 * 10);
                a2 = int(aa2 * 10);
                if (a1 > a2) {
                    int tem = a1;
                    a1 = a2;
                    a2 = tem;
                }
                int aaaa=1;
                int w= query(aaaa,h1,h2,a1,a2);
                if (w < 0) {
                    cout<<-1<<endl;
                }else{
                    double ans = w/ 10.0;
                    cout <<fixed<<setprecision(1)<< ans << endl;
                }
            }
        }
    }
    return 0;
}