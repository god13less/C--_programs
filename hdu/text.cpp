#include<bits/stdc++.h>
using namespace std;
#define enter puts("")
#define space putchar(' ')
#define Mem(a, x) memset(a, x, sizeof(a))
#define In inline
typedef long long ll;
const int maxn = 1e5 + 5;
const ll mod = 998244353;
const int N = 30;
In ll read() {ll x; scanf("%lld", &x); return x;}
In void write(ll x) {printf("%lld", x);}

ll q2[maxn];
void init(){
    q2[0] = 1;
    for(int i = 1; i < maxn; ++i) q2[i] = (q2[i - 1] <<1) % mod;
}
In ll ADD(const ll& a, const ll& b) {
    return a + b < mod ? a + b : a + b - mod;
}

int n, Q;
ll a[maxn];

struct Tree
        {
    int l, r;
    ll sum, rsum, lzy;
    bool lft;
    In Tree operator + (const Tree& oth)const
    {
        Tree ret; ret.l = l, ret.r = oth.r;
        ret.sum = ADD(sum, oth.sum);
        ret.rsum = ADD(rsum, oth.rsum);
        ret.lzy = 0;
        ret.lft = lft | oth.lft;
        return ret;
    }
        }t[maxn << 2];
In void build(int L, int R, int now)
{
    t[now].l = L, t[now].r = R;
    if(L == R)
    {
        a[L] = read();
        t[now].sum = a[L] % mod, t[now].lzy = 0;
        t[now].rsum = 0;
        if(a[L]) t[now].lft = 1;
        for(int i = N; i >= 0; --i)
            if((a[L] >> i) & 1)
            {
                t[now].rsum = (1 << i) % mod;
                break;
            }
        return;
    }
    int mid = (L + R) >> 1;
    build(L, mid, now << 1), build(mid + 1, R, now << 1 | 1);
    t[now] = t[now << 1] + t[now << 1 | 1];
}
In void Change(int now, int d)
{
    ll tp = q2[d];
    t[now].sum = ADD(t[now].sum, t[now].rsum * (tp - 1 + mod) % mod);
    t[now].rsum = t[now].rsum * tp % mod;
    t[now].lzy += d;
}
In void pushdown(int now)
{
    if(t[now].lzy)
    {
        Change(now << 1, t[now].lzy), Change(now << 1 | 1, t[now].lzy);
        t[now].lzy = 0;
    }
}
In void update_low(int L, int R, int now)
{
    if(!t[now].lft) return;		//整个区间都是0了
    if(t[now].l == t[now].r)	//我竟然写成L == R，而且整场比赛没看出来
        {
        ll tp = a[L] & (-a[L]);
        if(tp == a[L])
        {
            t[now].rsum = t[now].sum = 0;
            t[now].lzy = t[now].lft = 0;
        }
        else
        {
            t[now].sum = ADD(t[now].sum, mod- tp % mod);
            a[L] -= tp;
        }
        return;
        }
    pushdown(now);
    int mid = (t[now].l + t[now].r) >> 1;
    if(R <= mid) update_low(L, R, now << 1);
    else if(L > mid) update_low(L, R, now << 1 | 1);
    else update_low(L, mid, now << 1), update_low(mid + 1, R, now << 1 | 1);
    t[now] = t[now << 1] + t[now << 1 | 1];
}
In void update_hig(int L, int R, int now)
{
    if(t[now].l == L && t[now].r == R)
    {
        Change(now, 1);
        return;
    }
    pushdown(now);
    int mid = (t[now].l + t[now].r) >> 1;
    if(R <= mid) update_hig(L, R, now << 1);
    else if(L > mid) update_hig(L, R, now << 1 | 1);
    else update_hig(L, mid, now << 1), update_hig(mid + 1, R, now << 1 | 1);
    t[now] = t[now << 1] + t[now << 1 | 1];
}
In ll query(int L, int R, int now)
{
    if(t[now].l == L && t[now].r == R) return t[now].sum;
    pushdown(now);
    int mid = (t[now].l + t[now].r) >> 1;
    if(R <= mid) return query(L, R, now << 1);
    else if(L > mid) return query(L, R, now << 1 |1);
    else return ADD(query(L, mid, now << 1), query(mid + 1, R, now << 1 | 1));
}

int main()
{
    int T = read();
    init();
    while(T--)
    {
        n = read();
        build(1, n, 1);
        Q = read();
        for(int i = 1; i <= Q; ++i)
        {
            int op = read(), L = read(), R = read();
            if(L > R) swap(L, R);
            if(op == 1) write(query(L, R, 1)), enter;
            else if(op == 2) update_low(L, R, 1);
            else update_hig(L, R, 1);
        }
    }
    return 0;
}