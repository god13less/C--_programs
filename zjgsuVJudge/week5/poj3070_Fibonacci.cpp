//
// Created by wang on 2021/3/31.
//
#include <iostream>
#include <cstring>

using namespace std;
typedef long long ll;

const ll mod = 10000;

struct node {
    ll x[2][2];

    node() {
        memset(x, 0, sizeof x);
    }
} A;


node mul(node a, node b) {
    node s;
    memset(s.x, 0, sizeof s.x);
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            for (int l = 0; l < 2; l++) {
                s.x[i][j] = (s.x[i][j] + a.x[i][l] * b.x[l][j]) % mod;
            }
        }
    }
    return s;
}

ll quickly_pow(node a, ll times, ll mod) {
    node ans;
    memset(ans.x, 0, sizeof ans.x);
    for (int i = 0; i < 2; i++) {
        ans.x[i][i] = 1;
    }
    while (times) {
        if (times & 1) {
            ans = mul(a, ans);
        }
        a = mul(a, a);
        times >>= 1;
    }
    ll an = ans.x[0][1];
    return an;
}

int main() {
    ll n;
    A.x[0][0] = A.x[0][1] = A.x[1][0] = 1;
    while (cin >> n) {
        if (n == 0) {
            cout << 0 << endl;
        } else if (n == -1) {
            return 0;
        } else {
            ll ans = quickly_pow(A, n, mod);
            cout<<ans<<endl;
        }
    }

    return 0;
}
