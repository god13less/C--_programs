//
// Created by wang on 2021/6/30.
//

#include <iostream>

#define inf 0x3f3f3f3f

using namespace std;
typedef long long ll;

int N, M, X;
int visit[1005], dis[1005];
int w[1005][1005];

void dijkstra(int x) {
    for (int i = 1; i <= N; i++) {
        visit[i] = 0;
    }
    visit[x] = 1;

    for (int i = 1; i <= N; i++) {
        dis[i] = w[x][i];
    }

    for (int i = 2; i <= N; i++) {
        int minn = inf, u;
        for (int j = 1; j <= N; j++) {
            if (!visit[j] && dis[j] < minn) {
                minn = dis[j];
                u = j;
            }
        }
        visit[u] = 1;
        for (int j = 1; j <= N; j++) {
            if (!visit[j] && dis[j] > dis[u] + w[u][j]) {
                dis[j] = dis[u] + w[u][j];
            }
        }
    }
}

int main() {
    cin >> N >> M >> X;
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            if (i == j) {
                w[i][j] = 0;
            } else {
                w[i][j] = inf;
            }
        }
    }
    int a, b, c;
    for (int i = 1; i <= M; i++) {
        cin >> a >> b >> c;
        if (w[a][b] > c) {
            w[a][b] = c;
        }
    }
    int way[1005];
    dijkstra(X);
    for (int i = 1; i <= N; i++) {
        way[i] = dis[i];
    }

    for (int i = 1; i <= N; i++) {
        for (int j = i + 1; j <= N; j++) {
            int tem = w[i][j];
            w[i][j] = w[j][i];
            w[j][i] = tem;
        }
    }

    dijkstra(X);
    int ans=0;
    for (int i = 1; i <=N ; i++) {
        ans = max(ans, way[i] + dis[i]);
    }
    cout<<ans<<endl;

    return 0;
}
