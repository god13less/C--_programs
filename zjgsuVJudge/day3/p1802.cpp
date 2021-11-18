//
// Created by wang on 2021/2/1.
//

#include <iostream>
#include <cstring>

using namespace std;
typedef long long ll;

ll n, x;
ll lost[1010], win[1010], use[1010], dp[1010];

int main() {
    while (cin >> n >> x) {
        memset(dp, 0, sizeof dp);
        for (int i = 1; i <= n; i++) {
            cin >> lost[i] >> win[i] >> use[i];
        }
        for (int i = 1; i <= n; i++) {
            for (int j = x; j >= use[i]; j--) {
                dp[j] = max(dp[j] + lost[i], dp[j - use[i]] + win[i]);
            }
            //key point
            for (ll j = use[i]-1; j >=0 ; j--) {
                dp[j] += lost[i];
            }
            //
        }
        cout << dp[x]*5 << endl;
    }
    return 0;
}
