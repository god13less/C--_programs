//
// Created by wang on 2021/1/30.
//

#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;
typedef long long ll;

int main() {
    int times, n;
    ll pd[101][101];
    while (cin >> times) {
        for (int i = 0; i < times; i++) {
            cin >> n;
            memset(pd, 0, sizeof pd);
            for (int j = 1; j <= n; j++) {
                for (int k = 1; k <= j; k++) {
                    cin >> pd[j][k];
                }
            }
            for (int j = 1; j <= n; j++) {
                for (int k = 1; k <= j; k++) {
                    pd[j][k] += max(pd[j - 1][k - 1], pd[j - 1][k]);
                }
            }
            ll max=pd[n][1];
            for (int j = 2; j <= n; j++) {
                if (max < pd[n][j]) {
                    max=pd[n][j];
                }
            }
            cout<<max<<endl;
        }
    }
    return 0;
}
