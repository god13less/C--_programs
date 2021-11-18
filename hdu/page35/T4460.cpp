//
// Created by wang on 2021/7/13.
//

#include <bits\stdc++.h>
using namespace std;
typedef long long ll;
int ans;
int f,n;
vector<int> h[1005];
int vis[1000+15];
void bfs(int x){
    if (!f) {
        return;
    }
    queue<int> que;
    memset(vis, -1, sizeof(vis));
    que.push(x);
    vis[x] = 0;
    while (!que.empty()) {
        int y = que.front();
        que.pop();
        if (vis[y] > ans) {
            ans = vis[y];
            if (ans > 6) {
                f=0;
                return;
            }
        }
        for (int i = 0; i < h[y].size(); i++) {
            if (vis[h[y][i]] == -1) {
                vis[h[y][i]]=vis[y]+1;
                que.push(h[y][i]);
            }
        }
    }
    for (int i = 0; i < n; i++) {
        if (vis[i] == -1) {
            f=0;
            return;
        }
    }
}

int main(){
    map<string,int> q;
    string s,s1,s2;
    while (cin >> n && n) {
        for (int i = 0; i < n; i++) {
            cin>>s;
            q[s]=i;
        }
        int m;
        cin>>m;
        for (int i = 0; i < m; i++) {
            cin>>s1>>s2;
            h[q[s1]].push_back(q[s2]);
            h[q[s2]].push_back(q[s1]);
        }
        ans = 0;
        f=1;
        for (int i = 0; i < n; i++) {
            bfs(i);
        }
        if (!f) {
            cout<<"-1\n";
        } else {
            cout<<ans<<endl;
        }
        for (int i = 0; i < n; i++) {
            h[i].clear();
        }
    }

    return 0;
}