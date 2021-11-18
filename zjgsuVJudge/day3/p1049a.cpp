//
// Created by wang on 2021/1/31.
//

#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;
typedef long long ll;
int dp[2000000];
int w[40];

int main() {
    int v, n,j;
    while (cin >> v>> n) {
        for (int i = 0; i < n; i++) {
            cin >> w[i + 1];
        }
        memset(dp,0,sizeof dp);
        for (int i = 1; i <= n; i++) {
            for (j = v; j >= w[i]; j--) {
                dp[j] = max(dp[j], dp[j - w[i]] + w[i]);
            }
        }
        cout<<v-dp[v]<<endl;
    }
    return 0;
}

