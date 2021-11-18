//
// Created by wang on 2021/5/24.
//
//Dijkstra算法
#include <bits/stdc++.h>

const int INF = 0x3f3f3f3f;
int m, s[1005], si, ei, e[1005], n;
int visit[1005];
int map[1005][1005];
int dis[1005];

struct node {
    int id;
    int val;

    friend bool operator<(node a, node b) {
        return a.val > b.val;
    }
} pre, nt;

void dijkstra(int s) {
    memset(visit, 0, sizeof visit);
    memset(dis, INF, sizeof dis);
    dis[s] = 0;
    priority_queue<node> q;
    pre.id = s;
    pre.val = 0;
    q.push(pre);
    while (!q.empty()) {
        pre = q.top();
        q.pop();
        visit[pre.id] = 1;
        for (int i = 1; i <= n; i++) {
            if (!visit[i] && dis[i] > map[pre.id][i] + pre.val) {
                dis[i] = map[pre.id][i] + pre.val;
                nt.id = i;
                nt.val = pre.val + map[pre.id][i];
                q.push(nt);
            }
        }
    }
}

int main() {
    while (cin >> m >> si >> ei) {
        n = 0;
        for (int i = 0; i <= 1005; i++) {
            for (int j = 0; j <= 1005; j++) {
                if (i == j) {
                    map[i][j] = 0;
                } else map[i][j] = INF;
            }
        }
        int a, b, c;
        for (int i = 1; i <= m; i++) {
            cin >> a >> b >> c;
            n = max(max(a, b), n);
            if (map[a][b] > c) {
                map[a][b] = map[b][a] = c;
            }
        }
        for (int i = 1; i <= si; i++) {
            cin >> s[i];
            map[0][s[i]] = map[s[i]][0] = 0;
        }
        for (int i = 1; i <= ei; i++) {
            cin >> e[i];
        }
        dijkstra(0);
        int mi = INF;
        for (int i = 1; i <= ei; i++) {
            mi = min(dis[e[i]], mi);
        }
        cout << mi << endl;
    }
    return 0;
}