//
// Created by wang on 2021/1/31.
//

#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;
typedef long long ll;
int dp[40][20000];
int w[40];

int main() {
    int v, n;
    while (cin >> v>> n) {
        for (int i = 0; i < n; i++) {
            cin >> w[i + 1];
        }
        memset(dp,0,sizeof dp);
        for (int i = 1; i <= n; i++) {
            for (int j = w[i]; j <= v; j++) {
                dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - w[i]] + w[i]);
            }
        }
        cout<<v-dp[n][v]<<endl;
    }
    return 0;
}
