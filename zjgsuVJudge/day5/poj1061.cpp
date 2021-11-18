//
// Created by wang on 2021/1/31.
//

#include <iostream>

using namespace std;
typedef long long ll;

ll X,Y,m,n,L;
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
    return 0;
}


int main() {
    while (cin >> X >> Y >> m >> n >> L) {
        ll a=m-n;
        ll c=Y-X;
        ll T,Q;
        solve_ex_gcd(a,L,c,T,Q);
        if (T!=-1) {
            cout<<T<<endl;
        } else {
            cout<<"Impossible"<<endl;
        }
    }
    return 0;
}
