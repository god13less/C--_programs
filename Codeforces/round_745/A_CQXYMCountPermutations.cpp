//
// Created by wang on 2021/9/30.
//cf#745（div2)
#include <bits/stdc++.h>
#define inf 0x3f3f3f3f
#define maxn 1000000

using namespace std;
typedef long long ll;

int t,mod=1e9+7;
ll n;

ll qwe(ll x){
    ll ans = 1;
    ans = ((ans * x) / 2)%mod;
    x--;
    while (x>0) {
        ans = (ans*x)%mod;
        x--;
    }
    return ans;
}

int main() {
    cin >> t;
    while (t--) {
        cin >> n;
        cout << qwe(2 * n)<<endl;
    }
    return 0;
}

