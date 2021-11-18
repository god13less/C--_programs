//
// Created by wang on 2021/3/31.
//

#include <iostream>
#include <cstring>

using namespace std;
typedef long long ll;

const ll mod = 9973;

struct node {
    ll x[15][15];

    node() {
        memset(x, 0, sizeof x);
    }
} A;

ll n, k;

ll quickly_pow(node a, ll times, ll mod);

node mul(node a, node b);

int main() {
    int T;
    cin >> T;
    for (int i = 0; i < T; i++) {
        cin >> n >> k;
        for (int j = 0; j < n; j++) {
            for (int l = 0; l < n; l++) {
                cin >> A.x[j][l];
            }
        }
        ll ans = quickly_pow(A, k, mod);
        cout << ans << endl;
    }
    return 0;
}

ll quickly_pow(node a, ll times, ll mod) {
    node ans;
    memset(ans.x, 0, sizeof ans.x);
    for (int i = 0; i < n; i++) {
        ans.x[i][i] = 1;
    }
    while (times) {
        if (times & 1) {
            ans = mul(a, ans);
        }
        a = mul(a, a);
        times >>= 1;
    }
    ll an = 0;
    for (int i = 0; i < n; i++) {
        an = (an + ans.x[i][i]) % mod;
    }
    return an;
}

node mul(node a, node b) {
    node s;
    memset(s.x, 0, sizeof s.x);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            for (int l = 0; l < n; l++) {
                s.x[i][j] = (s.x[i][j] + a.x[i][l] * b.x[l][j]) % mod;
            }
        }
    }
    return s;
}