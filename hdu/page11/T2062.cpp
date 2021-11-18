//
// Created by wang on 2021/5/23.
//

#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main(){
    ll i,n,t;
    ll m;
    ll c[21]={0},s[21];

    for (i = 1; i <21 ; i++) {
        c[i]=c[i-1]*(i-1)+1;
    }
    while (cin >> n >> m) {
        for (i = 0; i < 21; i++) {
            s[i]=i;
        }
        while (n > 0 && m > 0) {
            t = m / c[n] + (m % c[n] > 0 ? 1 : 0);
            if (t > 0) {
                cout<<s[t];
                for (i = t; i <=n; i++) {
                    s[i] = s[i + 1];
                }
                m -= ((t - 1) * c[n] + 1);
                putchar(m == 0 ? '\n' : ' ');
            }
            n--;
        }
    }
    return 0;
}
