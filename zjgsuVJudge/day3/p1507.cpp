//
// Created by wang on 2021/2/1.
//

#include <iostream>
#include <cstring>

using namespace std;
typedef long long ll;

ll V,M,N;
ll v[55],m[55],k[55];
ll dp[550][550];

int main() {
    cin>>V>>M>>N;
    for (int i = 1; i <= N; i++) {
        cin>>v[i]>>m[i]>>k[i];
    }
    memset(dp, 0, sizeof dp);
    for (int i = 1; i <= N; i++) {
        for (int j = V; j >=v[i] ; j--) {
            for (int l = M; l >= m[i]; l--) {
                dp[j][l] = max(dp[j][l], dp[j - v[i]][l - m[i]] + k[i]);
            }
        }
    }
    cout<<dp[V][M]<<endl;
    return 0;
}
