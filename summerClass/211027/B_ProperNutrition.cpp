//
// Created by wang on 2021/10/27.
//
#include <bits/stdc++.h>
#define inf 0x3f3f3f3f
#define maxn 1000000

using namespace std;
typedef long long ll;
inline int read(){
    int x=0;char ch;
    for(ch=getchar();!isdigit(ch);ch=getchar());
    for(;isdigit(ch);ch=getchar())x=(x<<1)+(x<<3)+(ch^48);
    return x;
}
ll ex_gcd(ll a, ll b, ll &x, ll &y) {
    ll GCD, t;
    if (!b) {
        x = 1;
        y = 0;
        return a;
    }
    GCD = ex_gcd(b, a % b, x, y);
    t = x;
    x = y;
    y = t - (a / b) * y;
    return GCD;
}

ll inv(int a, int mod) {
    ll x, y;
    ll GCD = ex_gcd(a, mod, x, y);
    return GCD ? (x % mod + mod) % mod : -1;
}

ll solve_ex_gcd(ll a, ll b, ll c, ll &x, ll &y)
{
    ll d = ex_gcd(a, b, x, y);
    if((c % d) != 0) {
        x = -1;
        y = -1;
        return -1;
    }
    x *= (c / d);
    b = abs(b / d);
    x %= b;
    while(x < 0) {
        x += b;
    }
    y = (c - a * x) / b;
    return 1;
}
int n,a,b;
void save(){
    ll x,y;
    ll bo = solve_ex_gcd(a, b, n, x, y);
    if (bo && (x >= 0 && y >= 0)) {
        cout << "YES" << endl << x << ' ' << (n-a*x)/b << endl;
    } else {
        cout << "NO" << endl;
    }

}

int main() {
    n=read();
    a = read();
    b = read();
    save();

    return 0;
}
