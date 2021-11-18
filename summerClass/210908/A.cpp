//
// Created by wang on 2021/9/8.
//

#include <iostream>

#define inf 0x3f3f3f3f

using namespace std;
typedef long long ll;


int t;
ll a, b, c, r, ans;

void salve() {
    ans = 0;
    if (a > b) {
        ll tem = a;
        a = b;
        b = tem;
    }
    ll n = c - r, m = c + r;
    if (m < b) {
        ans += b - m;
    }
    if (n > a) {
        ans += n - a;
    }
    if (ans > b - a) {
        ans = b - a;
    }
}

int main() {
    cin>>t;
    while (t--) {
        cin>>a>>b>>c>>r;
        salve();
        cout << ans << endl;
    }

    return 0;
}
