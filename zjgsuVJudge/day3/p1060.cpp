//
// Created by wang on 2021/1/31.
//

#include <iostream>
#include <cstring>

using namespace std;
typedef long long ll;

ll n, m, tem;
ll v[30], w[30], dp[30030];

int main() {
    while (cin >> n >> m) {
        memset(dp, 0, sizeof dp);
        for (int i = 1; i <= m; i++) {
            cin >> v[i] >> tem;
            w[i] = v[i] * tem;
        }
        for (int i = 1; i <= m; i++) {
            for (int j = n; j >= v[i]; j--) {
                dp[j]=max(dp[j],dp[j-v[i]]+w[i]);
            }
        }
        cout<<dp[n]<<endl;
    }
    return 0;
}
