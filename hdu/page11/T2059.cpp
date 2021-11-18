//
// Created by wang on 2021/5/21.
//
//简单DP
#include <bits/stdc++.h>

#define INF 0x3F3F3F3F
using namespace std;
typedef long long ll;

int main() {
    int l, n, c, t, vr, vt1, vt2;
    double T1;
    int dist[102];
    while (cin >> l) {
        cin >> n >> c >> t >> vr >> vt1 >> vt2;
        for (int i = 1; i < n + 1; i++) {
            cin >> dist[i];
        }
        T1 = l * 1.0 / vr;
        double dp[150];
        for (double &i : dp) {
            i = INF * 2;
        }
        dp[0] = 0;
        dist[0] = 0;
        dist[n + 1] = l;
        for (int i = 0; i < n + 1; i++) {
            for (int j = i + 1; j <= n + 1; j++) {
                int x, y;
                if (c > dist[j] - dist[i]) {
                    x = dist[j] - dist[i];
                    y = 0;
                } else {
                    x = c;
                    y = dist[j] - dist[i] - c;
                }
                if (i == 0) {
                    dp[j] = min(dp[j], dp[i] + x * 1.0 / vt1 + y * 1.0 / vt2);
                } else {
                    dp[j] = min(dp[j], dp[i] + t + x * 1.0 / vt1 + y * 1.0 / vt2);
                }
            }
        }
        if (dp[n+1] < T1) {
            cout << "What a pity rabbit!" << endl;
        } else {
            cout << "Good job,rabbit!" << endl;
        }
    }
    return 0;
}
