//
// Created by wang on 2021/10/13.
//

#include <bits/stdc++.h>
#define inf 0x3f3f3f3f
#define maxn 1000000

using namespace std;
typedef long long ll;
typedef long double ld;
ld n,tem;
ld sum,ans;

map<ld , ld> ma;

int main() {
    cin >> n;
    ans=0;
    sum=0;
    for (int i = 1; i <= n; i++) {
        cin >> tem;
        ans += (i-1) * tem - sum + ma[tem + 1] - ma[tem - 1];
        ma[tem]++;
        sum += tem;
    }
    cout<<fixed<<setprecision(0)<<ans<<endl;
    return 0;
}