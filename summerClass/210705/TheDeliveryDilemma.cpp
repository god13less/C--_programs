//
// Created by wang on 2021/7/5.
// Codeforces 681 div2

#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstring>

#define maxn 200005

using namespace std;
typedef long long ll;
ll t,n;
ll sum[maxn];
pair<ll,ll> ps[maxn];

int main() {
    cin >> t;
    for (int i = 0; i < t; i++) {
        cin>>n;
        for (int j = 0; j < n; j++) {
            cin>>ps[j].first;
        }
        for (int j = 0; j < n; j++) {
            cin>>ps[j].second;
        }
        sort(ps, ps + n);
        for (int j = 0; j < n; j++) {
            sum[j+1]=sum[j]+ps[j].second;
        }
        ll res=sum[n];
        for (int j = 0; j < n; j++) {
            ll t = max(ps[j].first, sum[n] - sum[j + 1]);
            res = min(res, t);
        }
        cout<<res<<endl;
    }

    return 0;
}