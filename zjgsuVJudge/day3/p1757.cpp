//
// Created by wang on 2021/2/2.
//

#include <iostream>
#include <cstring>

using namespace std;
typedef long long ll;

ll M, N, temM, temW, temG, groupNumber;
ll group[1010],dp[1010];//group[]来记录每组的物品个数
ll G[1010][1010][2];//0:M,1:W;

int main() {
    cin >> M >> N;
    memset(G, 0, sizeof G);
    memset(group, 0, sizeof group);
    for (int i = 0; i < N; i++) {
        cin >> temM >> temW >> temG;
        groupNumber = max(groupNumber, temG);
        group[temG]++;
        G[temG][group[temG]][0] = temM;
        G[temG][group[temG]][1] = temW;
    }
    for (int i = 1; i <= groupNumber; i++) {
        for (int j = M; j >= 0; j--) {
            for (int k = 1; k <= group[i]; k++) {
                if (j >= G[i][k][0]) {
                    dp[j]=max(dp[j],dp[j-G[i][k][0]]+G[i][k][1]);
                }
            }
        }
    }
    cout<<dp[M]<<endl;
    return 0;
}
