//
// Created by wang on 2021/8/14.
//

#include <bits\stdc++.h>
#define inf 0x3f3f3f3f
const int N=100050;

using namespace std;
typedef long long ll;
int n,m,l,r;
vector<int> city[N];
int te[N],vis[N];

int BFS(int x){
    int ans=0;
    queue<int> que;
    que.push(x);
    vis[x] = 1;
    ans++;
    while (!que.empty()) {
        int tem =que.front();
        que.pop();
        for (int i = 0; i < city[tem].size(); i++) {
            int tem2 = city[tem][i];
            if (!vis[tem2] && te[tem2] <= r && te[tem2] >= l) {
                que.push(tem2);
                vis[tem2]=1;
                ans++;
            }
        }

    }
    return ans;
}

int main() {
    cin >> n;
    int u,v;
    for (int i = 1; i <= n - 1; i++) {
        cin>>u>>v;
        city[u].push_back(v);
        city[v].push_back(u);
    }
    for (int i = 1; i <= n; i++) {
        cin >> te[i];
    }
    cin>>m;
    int x;
    for (int i = 1; i <= m; i++) {
        cin>>x>>l>>r;
        memset(vis, 0, sizeof vis);
        if (te[x] < l | te[x] > r) {
            cout << 0 << endl;
        } else {
            cout<<BFS(x)<<endl;
        }
    }
    return 0;
}