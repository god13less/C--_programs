//
// Created by wang on 2021/1/30.
//

#include <iostream>

using namespace std;
typedef long long ll;

ll quick_pow(ll a, ll b, ll c) {
    ll ans = 1, base = a;
    while (b != 0) {
        if (b & 1) {
            ans = ans * base % c;
        }
        base = base * base % c;
        b >>= 1;
    }
    return ans;
}

int main() {
    ll n,x;
    while (cin >> n) {
        for (int i = 0; i < n; i++) {
            cin>>x;
            cout<<quick_pow(x,x,10)<<endl;
        }
    }

    return 0;
}
