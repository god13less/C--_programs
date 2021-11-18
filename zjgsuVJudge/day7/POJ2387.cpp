//
// Created by wang on 2021/3/6.
//
//前向星
#include <iostream>
#include <queue>
#define inf 0x3fffffff

using namespace std;
typedef long long ll;

ll cnt = 0;
ll head[1005];

struct Edge {
    int v, w;
    int next;
} edge[4050];

void add(int u, int v, int c) {
    cnt++;
    edge[cnt].v=v;
    edge[cnt].w=c;
    edge[cnt].next=head[u];
    head[u] = cnt;
}

ll T, N;
ll dis[1005];

void dijkstra(int x) {
    int visit[1005] = {0};
    visit[x] = 1;
    for (int i = 1; i <=N ; i++) {
        dis[i]=inf;
    }
    dis[x]=0;
    queue<int> q;
    q.push(x);
    visit[x]=1;
    while (!q.empty()) {
        int now =q.front();
        q.pop();
        visit[now]=0;
        for (int i = head[now]; i; i = edge[i].next) {
            int y=edge[i].v;
            int v=edge[i].w;
            if (dis[now] + v < dis[y]) {
                dis[y]=dis[now]+v;
                if (visit[y] == 0) {
                    q.push(y);
                    visit[y]=1;
                }
            }
        }
    }
}

int main() {
    ll a, b, c;
    cin>>T>>N;
    for (int i = 0; i < T; i++) {
        cin >> a >> b >> c;
        add(a, b, c);
        add(b, a, c);
    }
    dijkstra(1);
    cout<<dis[N]<<endl;
    return 0;
}