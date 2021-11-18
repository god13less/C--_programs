#include<cmath>
#include<queue>
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;
typedef long long ll;
const int N=5005;
const ll INF=9e18;
inline int read(){
    int X=0,w=0;char ch=0;
    while(!isdigit(ch)){w|=ch=='-';ch=getchar();}
    while(isdigit(ch))X=(X<<3)+(X<<1)+(ch^48),ch=getchar();
    return w?-X:X;
}
struct node{
    ll x,y;
}a[N];
ll dis(int i,int j){
    return (a[i].x-a[j].x)*(a[i].x-a[j].x)+
    (a[i].y-a[j].y)*(a[i].y-a[j].y);
}
int n;
bool vis[N];//标记数组
ll d[N][N],w[N];//两个距离数组
ll prim(){
    //初始化数组
    for(int i=1;i<=n;i++) w[i]=INF,vis[i]=0;

    int u=1;vis[u]=1;w[u]=0;
    //以u点为起点更新数组w[]
    for(int v=1;v<=n;v++){
        if(!vis[v]&&w[v]>d[u][v]){
            w[v]=d[u][v];
        }
    }

    int num=0;ll ans=0;
    while(++num<n){
        ll minn=INF;
        //选择最短边
        for(int v=1;v<=n;v++){
            if(!vis[v]&&minn>w[v]){
                minn=w[v];
                u=v;
            }
        }
        //标记
        vis[u]=1;
        //选择最短边中的最大边
        ans=max(ans,minn);
        for(int v=1;v<=n;v++){
            if(!vis[v]&&w[v]>d[u][v]){
                w[v]=d[u][v];
            }
        }
    }
    return ans;
}
int main(){
    int T=read();
    while(T--){
        n=read();
        for(int i=1;i<=n;i++){
            a[i].x=read();a[i].y=read();
            for(int j=1;j<n;j++){
                d[i][j]=d[j][i]=dis(i,j);
            }
        }
        printf("%lld\n",prim());
    }
    return 0;
}