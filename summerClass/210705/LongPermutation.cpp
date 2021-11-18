//
// Created by wang on 2021/7/5.
// Codeforces 681 div2

#include <iostream>
#include <algorithm>
#define inf 0x3f3f3f3f

using namespace std;
typedef long long ll;
ll a[200009];
ll n,q,l,r,x;
void f(ll n){
    for (int i = 1; i <=n ; i++) {
        a[i]=i;
    }
}

int main() {
    cin>>n>>q;
    f(n);
    ll tem;
    for (int i = 0; i < q; i++) {
        cin>>tem;
        if (tem == 1) {
            cin>>l>>r;
            ll sum[200009];
            for (int j = 1; j <= r; j++) {
                sum[j] = sum[j - 1] + a[j];
            }
            cout<<sum[r]-sum[l-1]<<endl;
        } else {
            cin>>x;
            for (int j = 0; j < x; j++) {
                if (n <= 15) {
                    next_permutation(a+1, a + n+1);
                } else {
                    next_permutation(a+n-13,a+n+1);
                }
            }
        }
    }

    return 0;
}
