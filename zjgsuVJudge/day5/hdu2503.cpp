//
// Created by wang on 2021/1/30.
//

#include <iostream>

using namespace std;
typedef long long ll;

ll gcd(ll a, ll b) {
    if (b == 0) {
        return a;
    }
    return gcd(b, a % b);
}

int main() {
    ll n, a, b, c, d, e, f, tem;
    while (cin >> n) {
        for (int i = 0; i < n; i++) {
            cin >> a >> b >> c >> d;
            e = a * d + b * c;
            f = b * d;
            tem = gcd(e, f);
            e = e / tem;
            f = f / tem;
            cout<<e<<" "<<f<<endl;
        }
    }

    return 0;
}
