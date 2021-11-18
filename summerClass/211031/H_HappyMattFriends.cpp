//
// Created by wang on 2021/10/31.
//
#include <iostream>
#include <cstring>

#define inf 0x3f3f3f3f
#define maxn 50

using namespace std;
typedef long long ll;

int t, n, m;
int arr[maxn];
int dp[2][1 << 20];

int main() {
    cin >> t;
    for (int k = 1; k <= t; k++) {
        cin >> n >> m;
        for (int i = 1; i <= n; i++) {
            cin >> arr[i];
        }
        memset(dp, 0, sizeof dp);
        dp[0][0] = 1;
        for (int i = 1; i <= n; i++) {
            for (int j = 0; j < (1 << 20); j++) {
                dp[i%2][j] = dp[(i - 1)%2][j] + dp[(i - 1)%2][j ^ arr[i]];
            }
        }
        ll cnt = 0;
        for (int i = m; i < (1 << 20); i++) {
            cnt += dp[n % 2][i];
        }
        cout << "Case #" << k << ": " << cnt << endl;
    }
    return 0;
}
