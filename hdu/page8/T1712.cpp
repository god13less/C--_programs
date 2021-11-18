//
// Created by wang on 2021/7/10.
//

#include <iostream>
#include <cstring>

#define maxn 110

using namespace std;
typedef long long ll;

ll dp[maxn];
ll arr[maxn][maxn];

int main() {
    int n, m;
    while (cin >> n >> m) {
        if (n == 0 && m == 0) {
            break;
        }
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                cin >> arr[i][j];
            }
        }
        memset(dp, 0, sizeof dp);
        for (int i = 1; i <= n; i++) {//group
            for (int j = m; j >= 1; j--) {//容量
                for (int k = 1; k <= j; k++) {//k <= j? 不同课是不同组，所以天就是
                    if (dp[j]>dp[j-k]+arr[i][k]) {
                        dp[j]=dp[j];
                    } else {
                        dp[j]=dp[j-k]+arr[i][k];
                    }
                }
            }
        }
        cout<<dp[m]<<endl;
    }
    return 0;
}