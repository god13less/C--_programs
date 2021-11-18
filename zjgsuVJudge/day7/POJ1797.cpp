//
// Created by wang on 2021/6/28.
//
#include<cmath>
#include<cstdio>
#include<algorithm>

using namespace std;
int w[1010][1010];
int d[1010];
bool vis[1010];
int n,m;
void djs()
{
    for(int i=1; i<=n; i++)
    {
        d[i]=w[1][i];
        vis[i]=0;
    }
    for(int i=1; i<=n; i++)
    {
        int m=-1;
        int x=-1;
        for(int j=1; j<=n; j++)
            if(!vis[j]&&d[j]>m)
                m=d[x=j];
        if(x!=-1)
        {
            vis[x]=1;
            for(int j=1; j<=n; j++)
                if(!vis[j]&&d[j]<min(d[x],w[x][j]))
                    d[j]=min(d[x],w[x][j]);//维护d数组
        }
    }
}
int main()
{
    int T,t=1;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d%d",&n,&m);
        for(int i=1; i<=n; i++)
            for(int j=1; j<=n; j++)
                w[i][j]=i==j?0:-1;
        for(int i=1; i<=m; i++)
        {
            int x,y,z;
            scanf("%d%d%d",&x,&y,&z);
            if(w[x][y]<z)
                w[x][y]=w[y][x]=z;
        }
        djs();
        printf("Scenario #%d:\n%d\n\n",t++,d[n]);
    }
}


















/*
#include <iostream>

#define inf 0x3f3f3f3f

using namespace std;
typedef long long ll;

ll dis[1009], w[1000009];
ll v[1000009], u[1000009];

int main() {
    ll T, n, m;
    cin >> T;
    for (int i = 0; i < T; i++) {
        cin >> n >> m;
        for (int j = 1; j <= m; j++) {
            cin >> u[j] >> v[j] >> w[j];
        }
        for (int j = 1; j <= n; j++) {
            dis[j] = 0;
        }
        dis[1] = inf;
        for (int j = 1; j <= n - 1; j++) {
            for (int k = 1; k <= m; k++) {
                if (dis[v[k]] < min(dis[u[k]], w[k])) {
                    dis[v[k]] = min(dis[u[k]], w[k]);
                }
                if (dis[u[k]] < min(dis[v[k]], w[k])) {
                    dis[u[k]] = min(dis[v[k]], w[k]);
                }
            }
        }
        cout << "Scenario #" << i + 1 << ':' << endl;
        cout << dis[n] << endl << endl;
    }
    return 0;
}*/
